ej1:
	g++ -Wall -Wextra -Wpedantic -std=c++17 -I Ejercicio_1/headers -o ej1 Ejercicio_1/main_ej1.cpp Ejercicio_1/sources/*.cpp
	./ej1
	rm ej1
	rm -rf ej1.dSYM/

ej2:
	g++ -Wall -Wextra -Wpedantic -std=c++17 -I Ejercicio_2/headers -o ej2 Ejercicio_2/main_ej2.cpp Ejercicio_2/sources/*.cpp
	./ej2
	rm ej2
	rm -rf ej2.dSYM/

ej3:
	g++ -Wall -Wextra -Wpedantic -std=c++17 -o ej3 Ejercicio_3/main_ej3.cpp
	./ej3
	rm ej3
	rm -rf ej3.dSYM/