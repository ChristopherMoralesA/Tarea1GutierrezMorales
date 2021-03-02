# Tarea 1
# Microprocesadores y Microcontroladores
# Christopher Morales - Kenneth Gutierrez

# Metodo check_char
def check_char(X):
    try:
        a = ord(X)                    # Codigo ASCII guardado en la variable a

        if (65 <= a <= 90) or (97 <= a <= 122):       # Rango de aceptacion de
            # caracteres segun cod. ASCII
            return 0        # Caso exitoso: caracter entre A y Z mayus o minus
        else:
            return 1013         # Error 1013: cuando el char no es una letra
            # entre A y Z mayuscula o minuscula

    except TypeError:   # Caso en el que no se puede ejecutar la funcion ord()
        if type(X) == str:
            Y = 0  # Contador para recorrer el str
            for i in X:
                Y = Y + check_char(i)
            if Y == 0:
                return 7889  # Error 7889: Mas de un char del rango aceptable
            else:
                return 1013  # Error 1013 Mas de un caracter fuera del rango
        else:
            return 2018         # Error 2018: cuando no se ingresa un string


def caps_switch(X):
    R = check_char(X)                   # Guarda el resultado de check_char
    if(R == 0):
        if(X == X.upper()):         # Determina si el valor es mayus o minus
            return X.lower()                            # Caso MAYUS a minus
        else:
            return X.upper()                            # Caso minus a MAYUS
    else:
        return R                        # Caso de error en el valor ingresado
