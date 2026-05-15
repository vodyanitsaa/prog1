#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Windows-specifikus fejlécek kezelése
#ifdef _WIN32
    #include <io.h>    //_access()
#define F_OK 0
    #define access _access
#else
    #include <unistd.h> //Linux
#endif

#define VERSION "1.2.5"

void show_help() {
    printf("alap v%s\n\n"
           "Usage: alap <template_id> [option]\n\n"
           "Available options:\n"
           "  -h, --help         show this help\n"
           "  -v, --version      version info\n"
           "  --stdout           don't create source file, print result to stdout\n\n"
           "Available templates:\n"
           "  -py   Python 3 source code [alap.py]\n"
           "  -ru   Ruby source code [alap.ru]\n"
           "  -bs   Bash source code [alap.sh]\n"
           "  -c    C source code [alap.c]\n", 
           VERSION);
}

int main(int argc, char *argv[]) {
    int to_stdout = 0;

    if (argc == 1) {
        show_help();
        return 0;
    }

    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        printf("alap v%s\n", VERSION);
        return 0;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        show_help();
        return 0;
    }

    if (argc >= 3 && strcmp(argv[2], "--stdout") == 0)
        to_stdout = 1;

    const char *lang = argv[1];
    const char *filename = NULL;
    const char *content = NULL;

    if (strcmp(lang, "-py") == 0) {
        filename = "alap.py";
        content = "print(\"Hello World\")\n";
    } else if (strcmp(lang, "-ru") == 0) {
        filename = "alap.ru";
        content = "puts 'Hello World'\n";
    } else if (strcmp(lang, "-bs") == 0) {
        filename = "alap.sh";
        content = "#!/bin/bash\necho \"Hello World\"\n";
    } else if (strcmp(lang, "-c") == 0 || strcmp(lang, "-jc") == 0) {
        filename = "alap.c";
        content = "#include <stdio.h>\n\nint main() {\n    printf(\"Hello World\\n\");\n    return 0;\n}\n";
    } else {
        printf("Unknown template: %s\n", lang);
        return 1;
    }

    if (to_stdout) {
        printf("%s", content);
        return 0;
    }
    
    if (access(filename, F_OK) == 0) {
        printf("Error, %s already exists.\n", filename);
        return 1;
    }

    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("Error creating file");
        return 1;
    }
    fputs(content, f);
    fclose(f);

    printf("# '%s' was created.\n", filename);
    return 0;
}
