################################################################################
## FUNZIONI E VARIABILI
################################################################################
# classic definition
function [ret-args]=nome(in-args)
   does things
endfunction

# function handle
handle = @FUNC-NAME  # can refer to built-it, user defined

# anonymous function
@(x,y) 3*x+y*cos(x^y)

# handle to anonymous function
handle = @(x,y,z) x+y+z

# global var (mst be first line of function body)
global d
global r=3   # only clears with clear all

################################################################################
## OPERATIONS ON NUMERICAL FUNCTIONS
################################################################################
# function zero (where x-axis cross occurs)
[ZERO, FZERO] = fzero(FUNCTION,INTERVAL)    # INTERVAL=[x1,x2] contains ZERO

# bound function minimization
[MIN,FMIN,INFO]=fminbnd(FUN,x1,x2)  # FUN is handle or name
                                    # info=1 if convergent
                                    # info=0 reached max iteration
                                    # info=-1 user stopped

# maximization
g = @(x) -f(x)

# unbound function minimization
[MIN,FMIN,INFO]=fminsearch(FUNC,X0)   # x0 è la partenza

# other methods
[x,fval,info]=fminbnd(g,x1,x2)
[x,fval,info]=fminsearch(g,x0)

# function plot
fplot(FUNC,[XMIN,XMAX])   # plot function, FUNC is handle or string with name

# function zero
[ZERO,FZERO]=fzero(FUNC,X0)   # FUNC is handle or string with name

################################################################################
## INPUT, OUTPUT & MISC
################################################################################
    # print text or var value followed by CR
    disp("text to print")
    # print formatted text
    NUMBER_OF_CHAR=printf("the value is %f", VAR)
    # format specificators
    "%" + n$ + flags + width + precisione + sottotipo + conversion
    base 10 integer signed %i
    base 10 integer unsigned %u
    fixed point notation %f
    exponential notation %e
    compact notation %g
    character %c
    string %s
    # print text and evaluate ser input
    input("you wrote")
    # visualezza usage: MESSAGGIO, arresta esecuzione e torna a livello superiore
    usage(MESSAGGIO)

################################################################################
## FLOW CONTROL
################################################################################
# if statement
if n>0
    do_things
else
    do_other_things
end

# for statement
for i=1:2:20
    do_things
end

# while statement
while cond==true
    do_things
end

# switch case
switch var
   case "something"
       do_things
   case "something else"
       do_other_things
end

################################################################################
## VETTORI
################################################################################
   # definizione
   v=[0 1 2 3 4 5]=[0,1,2,3,4,5]
   w=1:0,5:5
   # somma degli elementi
   sum(v)
   # lunghezza del vettore
   lenght(v)
   # elemento minimo e massimo
   min(v)
   max(v)
   # trasposto
   u=v'
   # prodotto scalare
   v*u
   # prodotto elemento-per-elemento
   v.*u
   # concatenazione per righe
   [v;u]
   # concatenazione per colonne
   [v:u]
   # estrazione di un elemento
   v(4)
   # estrazione di elementi consecutivi
   v(2:4)
   # estrazione da un elemento in poi
   v(3:end)
   # estrazione penultimo elemento
   v(end-1)
   #aggiungi elemento
   v(end+1)
   # elementi pari/dispari
   v(2:2:end)
   v(1:2:end)
   # ordine inverso
   v(end:-1:1)
   # p-norma di un vettore
   norm(v,p)
      # Calcolo p-norma vettore
      n = input("Dimensione: ");
      v = rand(n,1)
      p = input("Ordine norma: ");
      norma = 0;
      for i=1:n
         norma = norma + v(i)^p;
      end
      norma = nthroot(norma,p)
   # vettori notevoli
   linspace(0,100,28)   # 28 elementi equispaziati fra 0 e 100
   
################################################################################
## MATRICI
################################################################################
   # definizione per elementi
   A=[1 2 3 4 5; 6 7 8 9 10; 11 12 13 14 15; 16 17 18 19 20; 21 22 23 24 25]
   # matrici notevoli
   zeros(N,M)  # matrice di zeri
   ones(N,M)   # matrice di uni
   eye(N,M)    # matrice diagonale unitaria
   rand(N,M)   # matrice casuale
   magic(N)    # matrice magica
   # seleziona elementi
   A(3,4)      # elemento di indici (3,4)
   A(:,3)      # tutta la 3a colonna
   A(2,:)      # tutta la 2a riga
   A(3:5,4)    # dal 3o al 5o elemento della 4a colonna
   A(3,2:end)  # dal 2o all'ultimo elemento della 3a riga
   A(end,end)  # ultimo elemento dell'ultima colonna
   # rimuovi righa o colonna
   A(2,:) = []
   A(:,4) = []
   # somma delle colonne
   sum(A)
   # dimensioni matrice
   size(A)
   # matrice inversa
   inv(A)
   # matrice trasposta
   A'
   # norma di una matrice
   norm(A,p)
   # rango
   rank(A)
   # riduzione per righe
   [RIDOTTA,COLONNE]=rref(A)

################################################################################
## 2D PLOT
################################################################################
plot(x1,y1,'<col1> <sty1> <mark1>',x2,y2,'<col2> <sty2> <mark2>',..)
   # <col>: b g r c y k w
   # <sty>: - : -. -- (none)
   # <mark>: . o x + * s d v ^ < > p h
   
# autoscaling
axis()

# axis limits and appearance
axis([xmin xmax ymin ymax])
axis('OPTIONS') # square, normal, auto

# control axes border
box #toggle
box on/off

# control grid
grid    #toggle
grid on/off
grid minor
grid minor on/off

# hold plot
hold    # toggle
hold on/off

# legend


# title
title('plot title')

# axes labels
xlabel('x axis label')
ylabel('y axis label')

# legend
legend('string1','string2',..)
legend('OPTIONS')   # show hide toggle boxon boxoff right left off 

# subplots
subplot(ROWNUM,COLNUM,INDEX)

# plot functions
fplot(FUNC,[XMIN,XMAX])   # plot function, FUNC is handle or string with name

################################################################################
## POLINOMI
################################################################################
vettore p dei coefficienti ordinati per grado decrescente
   # valutazione in un punto
   y=polyval[p,x] # valuta p in ogni elemento di x
   # radici
   roots(p)
   # derivata e integrale
   polyder(p)
   polyint(p)
   
################################################################################
## INTERPOLAZIONE
################################################################################
   # 1 dimensionale
   y_int=interp1(x,y,x_int,"METODO")   # interpola i dati (x,y) per trovare y_int alle coord x_int
   # 2 dimensionale
   z_int=interp2(x,y,x_int,y_int,"METODO")
   # metodi
   linear (default)   spline   pchip
   # polinomio che approssima nel senso dei minimi quadrati
   p=polyfit(x,y,GRADO)
   
################################################################################
## STRUTTURE DATI
################################################################################
collezione di coppie (campo,valore)
   # crea struttura
   STRUTTURA=struct([CAMPO1,VALORE1],[CAMPO2,VALORE2],..)
   # elenca campi delala struttura
   CAMPI=fieldnames(STRUTTURA)
   # imposta valore di un campo
   s=setfield(STRUTTURA,CAMPO,VALORE)
   STRUTTURA.CAMPO=VALORE
   # estrai valore di un campo
   VALORE=getfield(STRUTTURA,CAMPO)

################################################################################
## DECOMPOSIZIONI
################################################################################
   # qr A=QR
   [Q,R]=qr(A)
   # lu A=LU
   [L,U]=lu(A)
   # choleski A=U'U
   U=chol(A)