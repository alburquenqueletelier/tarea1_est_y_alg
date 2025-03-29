#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char *argv[])
{
    if (argc < 6)
    {
        printf("Modo de uso: %s <archivo_entrante.txt> <acción> <clave1> <clave2> <archivo_salida.txt> ", argv[0]);
        return;
    };

    if (strcmp(argv[2], "encode") == 0)
    {
    }
    else if (strcmp(argv[2], "decode") == 0)
    {
    }
    else
    {
        printf("Acción invalidad: usar \"encode\" o \"decode\"");
        return;
    }

    if (strlen(argv[3]) != strlen(argv[4]))
    {
        printf("Las claves deben tener el mismo largo");
        return;
    }

    if (strcmp(argv[1], argv[5]) == 0)
    {
        printf("Archivo de entrada y de salida deben tener distinto nombre");
        return;
    }

    FILE *input_file;
    FILE *output_file;
    input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("No se pudo abrir el archivo de entrada");
        return;
    }

    fseek(input_file, 0, SEEK_END);
    long int size = ftell(input_file);
    rewind(input_file); // fseek(input_file, 0, SEEK_SET);

    char *response_file = (char *)malloc(size+1);
    fread(response_file, sizeof(char), size, input_file);
    response_file[size] = '\0';

    int key1, key2;

    if (argv[2] == "encode"){
        key1 = 3;
        key2 = 4;
    } else {
        key1 = 4;
        key2 = 3;
    }

    for (long int i=0; i < size; i++)
    {
        for (int j = 0; j < strlen(argv[3]); j++)
        {
            if (tolower(response_file[i]) == tolower(argv[3][j]))
            {
                if (islower(response_file[i])){
                    response_file[i] = tolower(argv[key1][j]);
                } else {

                    response_file[i] = toupper(argv[key1][j]);
                }
            }
            else if (tolower(response_file[i]) == tolower(argv[4][j]))
            {
                if (islower(response_file[i])){
                    response_file[i] = tolower(argv[key2][j]);
                } else {

                    response_file[i] = toupper(argv[key2][j]);
                }
            }
            
        }
    }

    output_file = fopen(argv[5], "w");
    if (output_file == NULL)
    {
        printf("No se pudo crear el archivo de salida");
        return;
    }

    printf("Escribiendo archivo de salida\n");
    fprintf(output_file, "%s", response_file);
    fclose(input_file);
    fclose(output_file);
    return;
}