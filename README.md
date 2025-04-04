# Codificador/Decodificador de Texto

# Resumen

La siguiente aplicación es un ejemplo de como encriptar un mensaje reemplazando caracteres con otros. En este caso, se reemplaza cada letra del texto siguiendo esta regla: 

Dado dos stings ingresados por el usuario, se reemplaza cada caracter del texto que coincida con una letra del primer string por el caracter correspondiente del segundo string y vicebersa. 
EJ: si el primer string es "ohl" y el segundo string es "123" entonces el texto " hola mundo" se convertiría en "213a mund1". También permite reversar el proceso.

## Recomendación

Se sugiere utilizar Linux y compilar con gcc, ya que el archivo makefile está diseñado para compilar con gcc.

## Requerimientos

1. Compilador de C: gcc
2. make file

## Instalación
### Paso 1: crear ejecutable

*Si tienes linux puedes saltarte este paso ya que al clonar el repositorio tendrás el binario*
Debes crear el ejecutable con el compilador que tu tengas. Si tienes gcc, puedes hacerlo con el siguiente comando:

bash
```
gcc -o main main.c
```

### Paso 2: ejecutar programa

Una vez creado el binario ejecutalo en la consola con el siguiente comando y respetando el orden:
./main <inputfile.txt> <action> <key1> <key2> <outfile.txt> 
bash
```
./main text.txt encode ohl 123 codificado.txt
```
### Parámetros y Restricciones

*Todos los campos son requeridos*
*len(key1) = len(key2)*

| Campo          | Descripción                                        | Valores            | Ejemplo        |
| -------------- | -------------------------------------------------- | ------------------ | -------------- |
| inputefile.txt | El archivo que deseas codificar                    | *.txt              | text.txt       |
| action         | La acción que deseas realizar (encode o decode)    | "encode", "decode" | encode         |
| key1           | La primera clave para codificar                    | string             | ohl            |
| key2           | La segunda clave para codificar                    | string             | 123            |
| outfile.txt    | El archivo que se generará con el texto codificado | *.txt              | codificado.txt |