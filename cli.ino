
#include <avr/pgmspace.h>
#include "cli.h"

#include "cli_art.h"
#include "cli_callbacks.h"

#include "serial.h"


/* private: */
void ttcli::menue(parser::Argument *args, char *response)
{
    /* Print menue */
    
    art_printer(divider_art);

    art_printer(dyno_art);
    art_printer(ttsaurus_art);

    art_printer(divider_art);

    Serial.println("TTsaurus Dyno");
    Serial.println("");
    Serial.println("TEST <str> <float> \t \t test command");
}

void ttcli::begin(void)
{
    Serial.println("registering functions");

    registerCommand("help", "", (void (*)(CommandParser<>::Argument*, char*)) &ttcli::menue);
    //registerCommand("rawr", "", );

    registerCommand("start", "", cmd_start_callback);
    registerCommand("stop", "", cmd_stop_callback);

    //registerCommand("TEST", "sd", &cmd_start_callback);

}

void ttcli::run(void)
{
    if(serial_read(ttcli::line, ttcli::line_length) > 0)
    {
        ttcli::processCommand(line, response);
        Serial.println(response);
    }
}

void cmd_test(parser::Argument *args, char * response)
{
  Serial.print("string: "); Serial.println(args[0].asString);
  Serial.print("double: "); Serial.println(args[1].asDouble);
  strlcpy(response, "success", parser::MAX_RESPONSE_SIZE);
}

// 
// End of file.
//

