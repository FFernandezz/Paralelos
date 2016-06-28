Clock(): Retorna el tiempo del procesador consumido
cout<<"Número de click: "<<t1<<" "<<(((float)t1)/CLOCKS_PER_SEC)<<endl;
Respuesta del blockMultiplication---Número de click: 4 4e-06
Respuesta del blockMultiplication---Número de click: 6 6e-06

compilar el programa en valgrind
- g++ -g blockMulti.cpp -o BMulti.exe
- valgrind --tool=memcheck --leak-check=yes ./BMulti.exe


compilar el programa en valgrind y kcachegrind
- g++ -g blockMulti.cpp -o BMulti.exe
- valgrind --tool=callgrind  ./BMulti.exe
- kcachegrind callgrind.out.8331

