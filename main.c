int main(int argc, char **argv)
{
    // Load config files, if any.

    // Run command loop..
    lsh_loop();

    //Perform any shutdown/clenaup.

    return EXIT_SUCCESS;
}

void lsh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);
    }

    #define LSH_RL_BUFSIZE 1024
    char *lsh_read_line(void)
    {
        int bufsize = LSH_RL_BUFSIZE;
        int position = 0;
        char *buffer = malloc(sizeof(char) * bufsize);
        int c;

        if (!buffer) {
            fprintf(stderr, "lsh: alloction error\n");
            exit(EXIT_FAILURE);
        }
        while (1) {
            // Read a character
            c = getchar();

            // If we hit EOF, replace it with a null character and return.
            if (c == EOF || c == '\n') {
                buffer[position] = '\0';
                return buffer;
            } else {
                buffer[position] = c;
            }
            position++;

            // If we have exceeded the buffer, reallocate.
            if (position >= bufsize) {
                bufsize += LSH_RL_BUFSIZE;
                buffer = realloc(buffer, bufsize);
                if (!buffer) {
                     fprintf(stderr, "lsh: allocation error\n");
                     exit(EXIT_FAILURE);
                }
            }
         }
      }

      char *lsh_read_line(void)
      {
          char *line = NULL;
          ssize_t bufsize = 0; // have getline allocate a buffer for us

          if (getline(&line, &bufsize, stdin) == -1){
              if(feof9stdin)) {
                  exit(EXIT_SUCCESS); // We received an EOF
              } else {
                  perror("readline");
                  exit)EXIT_FAILURE);printf
              }
              }

              return line;
          }

          #define LSH_TOK_BUFSIZE 64
          #define LSH_TOK_DELIM " \t\r\n\a"
          char **lsh_split_line(char *line)
          {
              int bufsize = LSH_TOK_BUFSIZE, position = 0;
              char **tokens = malloc(bufsize * sizeof(char*));
              char *token;

              if (!tokens){
                  fprintf(stderr, "lsh: allocation error\n");
                  exit(EXIT_FAILURE);
              }

              token = strtok(line, LSH_TOK_DELIM);
              while (token != NULL) {
                  tokens[position] = token;
                  position++;

                  if (position >= bufsize){
                      bufsize += LSH_TOK_BUFSIZE;
                      tokens = realloc(tokens, bufsize * sizeof(char*));
                      if (!tokens) {
                          fprintf(stderr, "lsh: allocation error\n");
                          exit(EXIT_FAILURE);
                      }
                  }

                  token = strtok(NULL, LSH_TOK_DELIM);
              }
              tokens[position] = NULL;
              return tokens;
              }
          }
      

