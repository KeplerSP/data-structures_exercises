| Carpeta/Archivo | Función                                                                                                                       |
| --------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| **`apps/`**     | Contiene el **punto de entrada del programa**. Es donde está el `main()`.                                                     |
| **`include/`**  | Aquí encontramos los prototipos de las funciones. Contiene los **archivos de cabecera (`.h`)** con las declaraciones de clases y funciones.  |
| **`src/`**      | Contiene los **archivos fuente (`.cpp`)** con la lógica del proyecto. Implementa la lógica indicada en la cabecera.                                                      |
| **`obj/`**      | Guarda los **archivos objeto (`.o`)** generados tras compilar los `.cpp`. Son el código compilado, se enlazan para crear el ejecutable. |
| **`bin/`**      | (Generalmente) se usa para guardar el **ejecutable final** del programa (`./bin/programa`, por ejemplo).                      |
| **`Makefile`**  | Define cómo compilar tu proyecto (compilar `.cpp` → `.o`, luego enlazar `.o` → ejecutable).                                   |
| **`README.md`** | Documento de texto (en Markdown) con instrucciones sobre el proyecto.                                                         |
