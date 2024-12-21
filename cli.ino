
#include <avr/pgmspace.h>
#include "cli.h"

#include "cli_art.h"

/* private: */
void ttcli::menue(void)
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

void ttcli::run(void)
{
    if( ttcli::serial() > 0)
    {
        ttcli::processCommand(line, response);
        Serial.println(response);
    }
}

size_t ttcli::serial()
{
    size_t cmd_len = 0;

    if(Serial.available() > 0)
    {
        cmd_len = Serial.readBytesUntil('\n', line, line_length);
        line[cmd_len++] = '\0';
    }

    return cmd_len;
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

