#include<iostream>
#include<windows.h>

#define sec 1000

int main(){
    int cant_loops, segundos_de_video, segundos_de_webcam, segundos_de_espera;

    std::cout << "Cuantas veces queres que se cambie de ventana?" << std::endl;
    std::cin >> cant_loops;

    std::cout << "Cuantos segundos queres que se vea el video?" << std::endl;
    std::cin >> segundos_de_video;

    std::cout << "Cuantos segundos queres que se vea la webcam?" << std::endl;
    std::cin >> segundos_de_webcam;

    HWND ventana_consola = GetConsoleWindow();

    std::cout << "Elija la ventana del video y espere un momento" << std::endl;
    Sleep(7 * sec);

    HWND ventana1 = GetForegroundWindow();
    ShowWindow(ventana1, SW_HIDE);
    ShowWindow(ventana_consola, SW_RESTORE);
    std::cout << "Primera ventana lista" << std::endl;

    Sleep(1 * sec);
    std::cout << "Ahora elija la ventana de webcam y espere un momento" << std::endl;
    Sleep(5 * sec);

    HWND ventana2 = GetForegroundWindow();
    ShowWindow(ventana2, SW_HIDE);
    ShowWindow(ventana_consola, SW_RESTORE);
    std::cout << "Segunda ventana lista" << std::endl;

    for(int i = 0; i < 10; i++){
        std::cout << "Faltan " << (10 - i) << " segundos para ejecutarse" << std::endl;
        Sleep(1 * sec);
    }

    ShowWindow(ventana_consola, SW_HIDE);

    HWND ventana_frente = ventana1;
    HWND ventana_fondo = ventana2;
    HWND tmp;

    SetForegroundWindow(ventana1);
    ShowWindow(ventana_frente, SW_MAXIMIZE);

    segundos_de_espera = segundos_de_video;

    for(int i = 0; i < cant_loops; i++){
        Sleep(segundos_de_espera * sec);
        ShowWindow(ventana_frente, SW_HIDE);
        ShowWindow(ventana_fondo, SW_MAXIMIZE);
        SetForegroundWindow(ventana_fondo);
        tmp = ventana_frente;
        ventana_frente = ventana_fondo;
        ventana_fondo = tmp;
        if(segundos_de_espera == segundos_de_video){
            segundos_de_espera = segundos_de_webcam;
        } else {
            segundos_de_espera = segundos_de_video;
        }
    }

    ShowWindow(ventana1, SW_RESTORE);
    ShowWindow(ventana2, SW_RESTORE);

    return 0;
}
