#ifndef _GETCH_LIB_
#define _GETCH_LIB_

#include <iostream>

#ifdef LINUX

    #include <unistd.h>
    #include <termios.h>

    char getch(void)
    {
        char buf = 0;
        struct termios old = {0};

        fflush(stdout);

        if(tcgetattr(0, &old) < 0) perror("tcsetattr()");

        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;

        if(tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");

        if(read(0, &buf, 1) < 0) perror("read()");

        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;

        if(tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");

        printf("%c\n", buf);

        return buf;
    }

#elif WINDOWS

    char getch()
    {
        std::cout << "\n\nWINDOWS!!!!!\n\n";
    }

#else

    char getch()
    {
        std::cout << "\n\nERROR:" << 
            "Incorrect OS flag during the project building!\n" <<
            "Check CMakeLists.txt: add_definitions must be in the start of the file!\n\n";
        exit(-1);
    }

#endif


#endif