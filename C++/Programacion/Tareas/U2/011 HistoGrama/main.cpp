#include "Histograma.h"

int main(){
    CHistograma historgrama(3);
    historgrama.captura();
    historgrama.histograma();
    historgrama.~CHistograma();
}