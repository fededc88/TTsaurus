#ifndef __CLI_H__
#define __CLI_H__

#include <CommandParser.h>

#define LINE_LENGTH 80 /* default line length */

typedef CommandParser<> parser;

void cmd_test(parser::Argument *args, char *response);

class ttcli: public parser
{
    public:
        size_t line_length;

        /* Class Constructor */
        ttcli(int line_len = LINE_LENGTH)
        {
            line_length = line_len;

            registerCommand("TEST", "sd", &cmd_test);

        }

        void menue(void);
        void run(void);

    private:
        char line[LINE_LENGTH];
        char response[LINE_LENGTH];

        size_t serial(void);

};

#endif

// 
// End of file.
//
