clear all; clc;

function y = f(x)
    y = cos(x.^2./log(x));
endfunction

fplot(@f,[2,7]);
res = quad(@f,3,4)