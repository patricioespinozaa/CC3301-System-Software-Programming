# sort: Ordena ascendentemente un arreglo de enteros sin signo usando un
# algoritmo ridiculamente ineficiente.

# La funcion sort esta programada en assembler RiscV. El codigo equivalente
# en C esta comentado, mostrando la ubicacion de las variables en los
# registros.  La funcion recorre el arreglo revisando que los elementos
# consecutivos esten ordenados.  Si encuentra 2 elementos consecutivos
# desordenados, los intercambia y reinicia el recorrido del arreglo
# desde el comienzo.  El arreglo esta ordenado cuando se recorre
# completamente sin encontrar elementos consecutivos desordenados.

    .file "sort-rv.s"
    .text
    .globl sort         # Se necesita para que la etiqueta sea conocida en
                        # test-sort.c
    .type sort, @function # typedef unsigned int uint;
sort:                   # void sort(uint nums[], int n) { // registros a0, a1
    addi    sp,sp,-64   #   // Apila registro de activacion
    sw      ra, 60(sp)  #   // resguarda direccion de retorno
    sw      a0,56(sp)   #   uint *p= nums; // p esta en sp+56
    addi    a1,a1,-1    #   uint *ult= &nums[n-1]; // ult esta en sp+52
    slli    a1,a1,2     #   // tamanno del arreglo
    add     a1,a0,a1
    sw      a1,52(sp)
    sw      a0,48(sp)   #   // nums esta en direccion sp+48
    mv      t0,a0       #   // p esta en registro t0
                        #   while (p<ult) {
    j       .while_cond #     // la condicion del while se evalua al final
.while_begin:           #     // del ciclo para mayor eficiencia

    sw      t0,56(sp)   # resguardar p en memoria

    # Hasta aca no puede modificar nada

    #################################################
    ### Comienza el codigo que Ud. debe modificar ###
    #################################################

    # no puede alterar los registros s0-s11, si lo hace debe resguardarlos
    # en 0(sp), 4(sp), ... o 44(sp)
    ##### El valor de p esta temporalmente en el registro t0 #####
    # No puede hacer mas trabajo que la comparacion (no puede usar ret)

    lw      a0,0(t0)  # Cargar dirección de p[0] en a0, (primer string), 'load word from memory' 
    lw      a1,4(t0)  # Cargar dirección de p[1] en a1, (segundo string), 'load word from memory'

    # Inicializar registros temporales para el bucle
    li      t2, 0     # Indice para recorrer las cadenas, inicializa t2 en 0 'load immediate'
    # Se pasa a compare_loop

compare_loop:
    lb      t3, 0(a0)       # Cargar el primer caraccter de p[0] en t3, c1 = *s1;  
    lb      t4, 0(a1)       # Cargar el primer caracter de p[1] en t4, c2 = *s2;

    # Convertir t3 (*c1) a minúscula si es mayúscula
    li      t5, 'A'
    blt     t3, t5, check_t4 # Si *c1 = t3 < t5 = 'A'
    li      t5, 'Z'
    bgt     t3, t5, check_t4 # Si *c2 = t3 > t5 = 'Z'
    addi    t3, t3, 32      # Convertir a minuscula

check_t4: # (c >= 'A' && c <= 'Z')
    # Convertir t4 (*c2) a minúscula si es mayúscula
    li      t5, 'A'
    blt     t4, t5, compare_chars # *c2 = t4 < t5 = 'A'
    li      t5, 'Z'
    bgt     t4, t5, compare_chars # *c2= t4 > t5 = 'Z'
    addi    t4, t4, 32      # Convertir a minuscula

compare_chars:
    # Comparar los caracteres actuales
    bne     t3, t4, set_t1  # Si son diferentes, salir del for, (c1 != c2)

    beq     t3, zero, set_t1  # Si llegamos al final de la cadena, salir del for, (c1 == 0) 
    addi    a0, a0, 1  # Avanzar al siguiente carácter de p[0]; s1++
    addi    a1, a1, 1  # Avanzar al siguiente carácter de p[1]; s2++
    j       compare_loop

set_t1:
    sub     t1, t3, t4  # Guardar la diferencia de caracteres en t1, (c1 - c2)

    # En el registro t1 debe quedar la conclusion de la comparacion:
    # si t1<=0 p[0] y p[1] estan en orden y no se intercambiaran.

    #################################################
    ### Fin del codigo que Ud. debe modificar     ###
    #################################################

    # Desde aca no puede modificar nada
    # Si t1>0 se intercambian p[0] y p[1] y se asigna p= noms para revisar
    # nuevamente que los elementos esten ordenados desde el comienzo del arreglo

.decision:              #     if (0>=rc) {
    lw      t0,56(sp)   #       // p esta en registro t0
    blt     zero,t1,.else
    addi    t0,t0,4     #       p++; // avanzar en arreglo de enteros
    j       .while_cond #     }

.else:                  #     else { // intercambar p[0] y p[1], y reiniciar
    lw      a0,0(t0)    #       int aux= p[0]; // a0
    lw      a1,4(t0)    #       int aux2= p[1];
    sw      a0,4(t0)    #       p[0]= aux2;
    sw      a1,0(t0)    #       p[1]= aux;
    lw      t0,48(sp)   #       p= noms;
                        #     }

.while_cond:            #     // se evalua la condicion del while
    lw      t1,52(sp)   #     // ult esta en t1
    bltu    t0,t1,.while_begin #  // Condicion del while es p<ult
			#   }
    lw      ra,60(sp)   #   // Se restaura direccion de retorno
    addi    sp,sp,64    #   // Desapila registro de activacion
    ret			# }
