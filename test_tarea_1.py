import pytest                   # Se importa la biblioteca "pytest"
from tarea_1 import check_char  # Se importan las funciones del otro archivo
from tarea_1 import caps_switch


@pytest.mark.parametrize(
    "input1", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    )
def test_check_char_exito(input1):  # Prueba de exito de la func. "check_char"
    assert check_char(input1) == 0  # Se verifica que devuelva "0" caso exito


@pytest.mark.parametrize("input2", ["/", "@8", "_]", "}", "!#27.", ",<:=$+-"])
# Caso negativo para verificar el error "1013"
def test_check_char_1013(input2):
    assert check_char(input2) == 1013


@pytest.mark.parametrize("input3", ["pala", "aK", "TE", "Epa", "xy", "wu"])
# Caso negativo para verificar el error "7889"
def test_check_char_7889(input3):
    assert check_char(input3) == 7889


@pytest.mark.parametrize("input4", [2, 79, [1, 2, 3, 4],
                         ["1", "A", "E", "T"], (1, 3, "34", "t"), 90.78])
# Caso negativo para verificar el error"2018"
def test_check_char_2018(input4):
    assert check_char(input4) == 2018


# Parametros para probar el exito de la función "caps_switch"
@pytest.mark.parametrize(
    "input5, input6",
    [
        "aA", "bB", "cC", "dD", "eE", "fF", "gG", "hH", "iI", "jJ",
        "kK", "mM", "lL", "nN", "oO", "pP", "qQ", "rR", "sS", "tT",
        "uU", "vV", "wW", "xX", "yY", "zZ", "Aa", "Bb", "Cc", "Dd",
        "Ee", "Ff", "Gg", "Hh", "Ii", "Jj", "Kk", "Ll", "Mm", "Nn",
        "Oo", "Pp", "Qq", "Rr", "Ss", "Tt", "Uu", "Vv", "Ww", "Xx",
        "Yy", "Zz"
    ]
)
# Funcion de prueba para la función caps_switch
def test_caps_switch_exito(input5, input6):
    assert caps_switch(input5) == input6
