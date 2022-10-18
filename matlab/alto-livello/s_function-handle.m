clear all; clc;

function out = func(x)
    out = log(x.^2+1)+cos(x)-2;
endfunction

fplot(@func,[-5,5]);
[zero,fzero]=fzero(@func,3)
[min,fmin]=fminbnd(@func,-2,0)

########################################################################
clear all; clc;

function eqn = sistema(unk)
    x = unk(1);
    y = unk(2);
    z = unk(3);
    eqn(1) = exp(x*y)+3*z-1;
    eqn(2) = 1-y+3*x*y;
    eqn(3) = exp(x/z)+x*z;
endfunction

x0 = [1,1,1];

[X,fval,info] = fsolve(@sistema,x0)