
#include <math.h>

const char dyno_art[] PROGMEM = { 
"                        / `.   .' \n\
                .---.  <    > <    >  .---.\n\
                |    \\  \\ - ~ ~ - /  /    |\n\
                 ~-..-~             ~-..-~\n\
             \\~~~\\.'                    `./~~~/\n\
   .-~~^-.    \\__/                        \\__/\n\
 .'  O    \\     /               /       \\  \\ \n\
(_____,    `._.'               |         }  \\/~~~/\n\
 `----.          /       }     |        /    \\__/\n\
       `-.      |       /      |       /      `. ,~~|\n\
           ~-.__|      /_ - ~ ^|      /- _      `..-'   f: f:\n\
                |     /        |     /     ~-.     `-. _||_||_\n\
                |_____|        |_____|         ~ - . _ _ _ _ _>//\n"
};

const char ttsaurus_art[] PROGMEM = {
" _____ _____\n\
|_   _|_   _|__  __ _ _   _ _ __ _   _ ___\n\
  | |   | |/ __|/ _` | | | | '__| | | / __|\n\
  | |   | |\\__ \\ (_| | |_| | |  | |_| \\__ \\\n\
  |_|   |_||___/\\__,_|\\__,_|_|   \\__,_|___/\n"
};

void art_printer(const char * s1)
{
    char buff[CLI_ART_LINE_LENGTH];
    size_t nchar = 0, nlines = 0;

    double nlines_f = 0;

    /* Calculate the length of the string */
    nchar = strlen_P(s1);

    //Serial.println(nchar);

    nlines = modf(((double)nchar/CLI_ART_LINE_LENGTH), &nlines_f) == 0 ? (size_t) nlines_f : (size_t) (nlines_f + 1); 
    //Serial.println(nlines_f);
    //Serial.println(nlines);

    for(nlines; nlines > 0; --nlines)
    {

        if(nchar >= 80)
        {
            memcpy_P(buff, s1, 80);
            s1 += 80;
            nchar = nchar - 80;

        }
        else
        {
            memcpy_P(buff, s1, nchar );
            s1 += nchar;
            buff[nchar] = 0;

        }

        /* rawr!! */
        Serial.print(buff);
    }
}
    
// 
// End of file.
//
