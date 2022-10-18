function Xp=Volo_vert(t,X,m0,r,b,T,g,Drag_act)
% Funzione che calcola la accelerazione e la velocità del razzo in funzione 
% del tempo tenendo in conto l'accelerazione della gravità e la variazione 
%della massa
y=X(1);
v=X(2);

% Variazione della massa totale del razzo nel tempo
mt=m0*(1-r*t/b);  

% Calcolo della accelerazione con la 2da legge di Newton
% Se si considera resistenza aerodinámica Drag_act=1
switch Drag_act
    case 0
    %Equazione del moto per il caso senza resistenza aerodinamica
    dv_dt=T/mt-g;
    
    
    
    case 1
        %Equazione del moto per il caso con resistenza aerodinamica
        %Proprietà locali dell'aria
        R_aria=287;
        [pressione,temperatura,vel_suono]=atmosfera(y);
        densita=pressione/R_aria/temperatura;
        
        %Mach di volo
        Mach=abs(v/vel_suono);
        
        %Coefficiente di resistenza per condizioni locali dell'aria
        CD=CD_M(Mach,t,b);
        
        %Area di riferimento per CD
        Area=pi*0.24^2/4;

        %Spinta nulla dopo b
        if t>b
            T=0;
            mt=m0*(1-r)
        end
        
        %Accelerazione longitudinale
        dv_dt=T/mt-g-densita*v^2/2*Area*CD/mt;
    
end


Xp(1,1)=v;
Xp(2,1)=dv_dt;
end


function [pressione,temperatura,vel_suono]=atmosfera(h)

gamma_aria=1.4;

R_aria = 287;      %[J/(kg*K)]


if  h<=11000
    temperatura=288.2-0.0065.*h;                                               %[K]
    pressione=101300*((temperatura./288.2).^(-9.81/(-0.0065*287)));   %[Pa]
    vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;               % Velocità del suono [m/s]

elseif  h<=25000
        temperatura=216.7;                                         %[K]
        pressione=22620*exp(-9.81.*(h-11000)./(287*216.7));         %[Pa]
        vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;           %[m/s]
        
elseif h<=47000
            temperatura=216.7+0.003.*(h-25000);                                               %[K]
            pressione=2485.7*((temperatura./216.7).^(-9.81/(0.003*287)));   %[Pa]
            vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;               % Velocità del suono [m/s]
elseif h<=53000
            temperatura=282.66;                                               %[K]
            pressione=120.185*exp(-9.81.*(h-47000)./(287*282.66));   %[Pa]
            vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;               % Velocità del suono [m/s]
elseif h<=79000
            temperatura=282.66-0.0045.*(h-53000);                                               %[K]
            pressione=2485.7*((temperatura./282.66).^(-9.81/(-0.0045*287)));   %[Pa]
            vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;               % Velocità del suono [m/s]
elseif h<=90000
            temperatura=165.66;                                               %[K]
            pressione=42.94*exp(-9.81.*(h-79000)./(287*165.66));   %[Pa]
            vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;               % Velocità del suono [m/s]
elseif h<=105000
            temperatura=165.66+0.004.*(h-90000);                                               %[K]
            pressione=4.4377*((temperatura./165.66).^(-9.81/(0.004*287)));   %[Pa]
            vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;               % Velocità del suono [m/s]
else
            temperatura=165.66+0.004.*(h-90000);                                               %[K]
            pressione=0;   %[Pa]
            vel_suono=(gamma_aria*R_aria.*temperatura).^0.5;               % Velocità del suono [m/s]
end 
    
end


function CD=CD_M(M,t,b)

if t<=b
    %Drag vs Mach curve for the condition with the Engine OFF
    CDM=[0.00000000000  0.187096774194
    0.299663299663  0.187096774194
    0.501683501684  0.170161290323
    0.59595959596  0.172580645161
    0.69696969697  0.162903225806
    0.89898989899  0.199193548387
    1.19528619529  0.274193548387
    1.39730639731  0.293548387097
    1.59259259259  0.259677419355
    1.79461279461  0.233064516129
    1.99663299663  0.216129032258
    2.19865319865  0.201612903226
    2.39393939394  0.191935483871
    2.59595959596  0.179838709677
    2.79797979798  0.170161290323
    2.99326599327  0.162903225806
    3.20202020202  0.15564516129
    3.39057239057  0.150806451613
    3.59932659933  0.143548387097
    3.79461279461  0.138709677419
    3.9898989899  0.133870967742];
else
    %Drag vs Mach curve for the condition with the Engine ON
    CDM=[0.0000000 0.325
    0.299663299663  0.325
    0.501683501684  0.308064516129
    0.59595959596  0.308064516129
    0.69696969697  0.298387096774
    0.89898989899  0.332258064516
    1.19528619529  0.467741935484
    1.39730639731  0.477419354839
    1.59932659933  0.431451612903
    1.80134680135  0.395161290323
    1.99663299663  0.363709677419
    2.19865319865  0.337096774194
    2.40067340067  0.312903225806
    2.59595959596  0.293548387097
    2.79797979798  0.276612903226
    2.99326599327  0.259677419355
    3.19528619529  0.245161290323
    3.39730639731  0.233064516129
    3.59932659933  0.218548387097
    3.79461279461  0.208870967742
    3.99663299663  0.199193548387];
end


CD=interp1(CDM(:,1),CDM(:,2),M,'spline','extrap');


end