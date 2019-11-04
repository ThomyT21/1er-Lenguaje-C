#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* empleado;
    empleado = (Employee*)malloc(sizeof(Employee));

    if(empleado != NULL)
        {
            empleado->id = 0;



        }

return empleado;
}
