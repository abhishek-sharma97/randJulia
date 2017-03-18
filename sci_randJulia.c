/*
Name: Abhishek Sharma
Function details: randJulia calls the rand function from Julia language and provide the output to the scilab console
Input arguments: Positive integers
Output arguments: n-element array of random numbers, with n being the input argument
*/

#include "api_scilab.h"
#include "Scierror.h"
#include "localization.h"
#include "julia.h"

const char fname[] = "randJulia";

int sci_randJulia(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt opt, int nout, scilabVar* out)
{
    //check if the number of arguments is equal to one
    if (nin > 1 || nin < 1)
    {
        Scierror(999, _("%s: Wrong number of input arguments: %d expected.\n"), fname, 1);
        return STATUS_ERROR;
    }
    
    //check if the argument is a positive integer
    
    if (scilab_isInt(env, in[0]) == 0 || in[0] <= 0)
    {
        Scierror(999, _("%s: Wrong type of input arguments:integer expected.\n"), fname);
        return STATUS_ERROR;
    }

    //call rand function with the argument as rand function's argument

    jl_function_t *func = jl_get_function(jl_base_module, "rand");
    jl_value_t *argument = jl_box_int32(in[0]);
    jl_value_t *ret = jl_call1(func, argument); //using function call method jl_call1

    return ret;

    return STATUS_OK;
}
}
