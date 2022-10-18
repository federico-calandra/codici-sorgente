% Razzo_1.m
% 
% Codice di risoluzione di ODE del 1º ordine:
% Moto in volo verticale di un razzo
% 
% Variabili Input 
%  T = 48000 % [N]   - Spinta
% m0 = 2200  % [kg]  - Massa iniziale del razzo
%  r = 0.8   % mp/m0 - Rapporto massa di propellente/massa iniziale del razzo
%  b = 40    % [s]   - Burnout time
%  g = 9.81  %[m/s^2]- Accelerazione della gravità
% 
% 
% Output variable
% Vb - % [s] - Velocità al tempo b
% 
%  Licensing:
%
%    This code is distributed under the GNU LGPL license.
%
%  Modified:
%    12 Maggio 2017
%
%  Author:
%    Ing. Manuel Saravia
%
clear; close all; clc


 T = 48000; % [N]   - Spinta
m0 = 2200;  % [kg]  - Massa iniziale del razzo
 r = 0.8;   % mp/m0 - Rapporto massa di propellente/massa iniziale del razzo
 b = 40;    % [s]   - Burnout time
 g = 9.81;  %[m/s^2]- Accelerazione della gravità

% Variazione della massa totale del razzo nel tempo
mt=@(t) m0*(1-r*t/b);  


% Caso 1
% Calcolo della accelerazione con la 2da legge di Newton
dv_dt=@(t,v) T/mt(t)-g;

%Integrazione nel tempo
[t,V]=ode45(dv_dt,[0 b],0);

disp(' ')
disp('Caso 1')
disp(strcat(['La velocità finale è:',' ',num2str(V(end)),' [m/s]']))
disp('****************************************')

figure(1)
hold on
grid
xlabel('t [s]')
ylabel('V_{razzo} [m/s]')
plot(t,V,'LineWidth',1.5)
title('Velocità del razzo nel tempo')



% Caso 2 - Calcolo sia della velocità al variare dei parametri
 VT =35000:5000:55000;    % [N]   - Spinta
Vm0 =1500:500:3500;       % [kg]  - Massa iniziale del razzo
 Vr = 0.4:0.1:0.8;       % mp/m0 - Rapporto massa di propellente/massa iniziale del razzo
 Vb = 20:10:50;          % [s]   - Burnout time

figure(2)
subplot(2,2,1)
hold on
grid
xlabel('t [s]')
ylabel('V_{razzo} [m/s]')
title('Velocità del razzo nel tempo al variare di T')

 
for T=VT
    mt=@(t) m0*(1-r*t/b);  
    dv_dt=@(t,v) T/mt(t)-g;

    %Integrazione nel tempo
    [t,V]=ode45(dv_dt,[0 b],0);

    plot(t,V,'LineWidth',1.5)
                
end

 T = 48000; % [N]   - Spinta
m0 = 2200;  % [kg]  - Massa iniziale del razzo
 r = 0.8;   % mp/m0 - Rapporto massa di propellente/massa iniziale del razzo
 b = 40;    % [s]   - Burnout time
 g = 9.81;  %[m/s^2]- Accelerazione della gravità

subplot(2,2,2)
hold on
grid
xlabel('t [s]')
ylabel('V_{razzo} [m/s]')
title('Velocità del razzo nel tempo al variare di m_0')

 

for m0=Vm0
    mt=@(t) m0*(1-r*t/b);  
    dv_dt=@(t,v) T/mt(t)-g;

    %Integrazione nel tempo
    [t,V]=ode45(dv_dt,[0 b],0);

    plot(t,V,'LineWidth',1.5)

end


subplot(2,2,3)
hold on
grid
xlabel('t [s]')
ylabel('V_{razzo} [m/s]')
title('Velocità del razzo nel tempo al variare di r')

  T = 48000; % [N]   - Spinta
m0 = 2200;  % [kg]  - Massa iniziale del razzo
 r = 0.8;   % mp/m0 - Rapporto massa di propellente/massa iniziale del razzo
 b = 40;    % [s]   - Burnout time
 g = 9.81;  %[m/s^2]- Accelerazione della gravità


for r=Vr
    mt=@(t) m0*(1-r*t/b);  
    dv_dt=@(t,v) T/mt(t)-g;

    %Integrazione nel tempo
    [t,V]=ode45(dv_dt,[0 b],0);

    plot(t,V,'LineWidth',1.5)
end


subplot(2,2,4)
hold on
grid
xlabel('t [s]')
ylabel('V_{razzo} [m/s]')
title('Velocità del razzo nel tempo al variare di b')

  T = 48000; % [N]   - Spinta
m0 = 2200;  % [kg]  - Massa iniziale del razzo
 r = 0.8;   % mp/m0 - Rapporto massa di propellente/massa iniziale del razzo
 b = 40;    % [s]   - Burnout time
 g = 9.81;  %[m/s^2]- Accelerazione della gravità

for b=Vb
    mt=@(t) m0*(1-r*t/b);  
    dv_dt=@(t,v) T/mt(t)-g;

    %Integrazione nel tempo
    [t,V]=ode45(dv_dt,[0 b],0);

    plot(t,V,'LineWidth',1.5)

end


% Caso 3 - Calcolo sia della velocità e della altitudine

X0=[0 0];

 T = 48000; % [N]   - Spinta
m0 = 2200;  % [kg]  - Massa iniziale del razzo
 r = 0.8;   % mp/m0 - Rapporto massa di propellente/massa iniziale del razzo
 b = 40;    % [s]   - Burnout time
 g = 9.81;  %[m/s^2]- Accelerazione della gravità

 
 %Calcolo con o senza resistenza aerodinamica
 Drag_act=0;
 Volo_vert_2=@(t,X) Volo_vert(t,X,m0,r,b,T,g,Drag_act);

 
 
%Integrazione nel tempo
[t,V]=ode45(Volo_vert_2,[0 b],X0);

disp(' ')
disp('Caso 3')
disp(strcat(['La velocità finale è:',' ',num2str(V(end,2)),' [m/s]']))
disp(' ')
disp(strcat(['La altitudine finale è:',' ',num2str(V(end,1)/1000),' [km]']))

figure(3)
hold on
grid
xlabel('t [s]')

plotyy(t,V(:,1)/1000,t,V(:,2))
legend('Altitude [km]','Velocity [m/s]')


%******************************************************************************************
%Caso con resistenza aerodinamica
Drag_act=1;
Volo_vert_2=@(t,X) Volo_vert(t,X,m0,r,b,T,g,Drag_act);

%Integrazione nel tempo
[t,V]=ode45(Volo_vert_2,[0 b+150],X0);

figure(4)
hold on
grid
xlabel('t [s]')

plotyy(t,V(:,1)/1000,t,V(:,2))
legend('Altitude [km]','Velocity [m/s]')
