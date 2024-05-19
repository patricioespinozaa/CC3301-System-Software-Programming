#include <stdio.h>

char sumarStr(char *a, char *b) {
    char *pa = a;
    char *pb = b;

    // Calcular la longitud de a y b
    int len_a = 0;
    while (*pa != '\0') {
        len_a++;
        pa++;
    }

    int len_b = 0;
    while (*pb != '\0') {
        len_b++;
        pb++;
    }

    // Verificar que a y b tengan la misma longitud
    if (len_a != len_b) {
        return '1'; // Longitudes diferentes, retorno '1'
    }

    // Sumar los dígitos de a y b
    pa = a;
    pb = b;
    char carry = 0;
    while (*pa != '\0') {
        char sum = (*pa - '0') + (*pb - '0') + carry;
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        *pa = sum + '0'; // Actualizar el dígito en a
        pa++;
        pb++;
    }

    if (carry == 1) {
        return '1'; // Suma no representable, retorno '1'
    } else {
        return '0'; // Suma exitosa, retorno '0'
    }
}

int main() {
    char a[] = "068";
    char b[] = "045";

    char resultado = sumarStr(a, b);
    printf("Resultado: %c\n", resultado); // Debería imprimir '0'
    printf("a: %s\n", a); // Debería imprimir "113"

    return 0;
}
