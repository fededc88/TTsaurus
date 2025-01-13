
#include "cli_callbacks.h"

#include <stdio.h>

void cmd_start_callback(CommandParser<>::Argument *args, char* response)
{
    sprintf(response, "Start Callback");

}
void cmd_stop_callback(CommandParser<>::Argument *args, char* response)
{
    sprintf(response, "Stop Callback");

}

/* cmd_callback example */
// void cmd_test_callback(parser::Argument *args, char * response)
// {
//   Serial.print("string: "); Serial.println(args[0].asString);
//   Serial.print("double: "); Serial.println(args[1].asDouble);
//   strlcpy(response, "success", parser::MAX_RESPONSE_SIZE);
// }

// 
// End of the file
//

