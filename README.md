## ProyectoIOT
Proyecto funcional para departamento

## Descripción
Este proyecto consiste en un sistema funcional para un departamento en el cual los dispositivos pueden ser encendidos y apagados simplemente con un aplauso. Utilizando tecnología de detección de sonido, el sistema interpreta los aplausos como comandos para controlar los dispositivos conectados.

## Objetivo
El objetivo principal de este proyecto es facilitar la forma en la cual los dispositivos eléctricos pueden ser encendidos y apagados, permitiendo a los usuarios realizar esta tarea desde la comodidad de su cama o cualquier otro lugar donde se encuentren dentro del alcance del sistema. Esto proporciona comodidad y accesibilidad a los usuarios, eliminando la necesidad de levantarse o buscar controladores físicos.

## Software Utilizado

| Nombre    | Versión           | Tipo                |
|-----------|-------------------|---------------------|
| Arduino     | Versión más Reciente | Interprete de Código |
| Postgres  | Versión más Reciente | Base de Datos SQL    |
| Grafana   | Versión más Reciente | Monitoreo de Datos   |
| Node-red  | Versión más Reciente | Conexión a Internet |

# Configuración de Hardware

## Descripción
La configuración de hardware utilizada en este proyecto es fundamental para el funcionamiento del sistema de control de dispositivos con aplausos. A continuación se detallan los componentes principales necesarios para implementar el sistema.

## Hardware Utilizado

| Imagen                                                                 | Nombre de Hardware   | Tipo                          | Cantidad | Precio  |
|------------------------------------------------------------------------|----------------------|-------------------------------|----------|---------|
| <img src="https://m.media-amazon.com/images/I/715lLPSw2GL._AC_UF894,1000_QL80_.jpg" alt="Raspberry Pi 4" height="50px"/>     | Raspberry Pi 4       | Placa de Desarrollo           | 1        | $1400   |
| <img src="https://uelectronics.com/wp-content/uploads/AR1191-ESP32-38-Pin.jpg" alt="ESP32" height="60px"/>              | ESP32                | Microcontrolador              | 3        | $160    |
| <img src="https://esphome.io/_images/ssd1306-full.jpg" alt="OLED" height="50px"/>               | OLED                 | Pantalla                      | 1        | $60     |
| <img src="https://proserquisa.com/principal/inicio/uploads/modulo-rele.jpg" alt="Relé" height="50px"/>               | Relé                 | Dispositivo de Conmutación    | 2        | $45     |
| <img src="https://www.prometec.net/wp-content/uploads/2016/04/sensor-sonido-ky-038.jpg" alt="KY-038" height="50px"/>             | KY-038               | Sensor de Sonido              | 2        | $20     |
| <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR72bsW5fJ_Yzoi3y140iJAni_YL3GibPNdmW6QuosD0ugU3fIvtoD8RDDy9YskG4LSeiA&usqp=CAU" alt="Foco" height="50px"/>               | Foco                 | Dispositivo de Iluminación    | 1        | $20     |
| <img src="https://www.vaqueiros.mx/wp-content/uploads/2023/09/socket-para-foco-volteck-de-porcelana-3-1-2-redonda-popo-15-46523-e1693607611662.jpg" alt="Socket" height="50px"/>             | Socket               | Conector Eléctrico            | 1        | $10     |
| <img src="https://encrypted-tbn0.gstatic.com/shopping?q=tbn:ANd9GcQj7ylRem2zsCZAH2h5xt8ZeS1ZcBNYsiwAo1qg38h167m-CAcFMluqgkR6OklqkTG2cD_EeRhkPWkc8_p_ya0o2t7WPIZYs7BklmjoUh5nYaqeK-PqQdvA&usqp=CAE" alt="Extensión Eléctrica" height="50px"/>| Extensión Eléctrica | Accesorio                     | 2        | $70     |
| <img src="https://i5.walmartimages.com.mx/mg/gm/3pp/asr/63f726eb-6ca9-47c6-8132-176792c8505c.795187b5f121b42a748a4de704a052e8.jpeg?odnHeight=612&odnWidth=612&odnBg=FFFFFF" alt="Ventilador" height="50px"/>        | Ventilador           | Dispositivo de Ventilación    | 1        | $100    |
| <img src="https://www.prometec.net/wp-content/uploads/2014/10/buzzer.jpg" alt="Buzzer" height="50px"/>            | Buzzer               | Dispositivo Acústico          | 2        | $15     |
| <img src="https://www.steren.com.mx/media/catalog/product/cache/295a12aacdcb0329a521cbf9876b29e7/image/1512680a5/placa-fenolica-perforada-con-pistas-de-7-5-cm-x-4-5-cm.jpg" alt="Placa Fenólica" height="50px"/>    | Placa Fenólica       | Material de Construcción      | 1        | $20     |
| <img src="https://m.media-amazon.com/images/I/61+nStDwtIL._AC_UF1000,1000_QL80_.jpg" alt="Placa Protoboard" height="50px"/>  | Placa Protoboard     | Accesorio                     | 3        | $100    |
| <img src="https://www.steren.com.mx/media/catalog/product/cache/bb0cad18a6adb5d17b0efd58f4201a2f/image/222589050/juego-de-120-cables-de-20-cm-tipo-dupont.jpg" alt="Cables Dupont" height="50px"/>     | Cables Dupont        | Accesorios                    | 120      | $100    |
| <img src="https://static.wixstatic.com/media/d96bda_eb68a6df87924bafb8a2c84d4334f755~mv2.jpg/v1/fill/w_480,h_480,al_c,q_80,usm_0.66_1.00_0.01,enc_auto/d96bda_eb68a6df87924bafb8a2c84d4334f755~mv2.jpg" alt="DHT11" height="50px"/>             | DHT11                | Sensor de Humedad y Temperatura | 1     | $50     |
| <img src="https://www.steren.com.mx/media/catalog/product/cache/0236bbabe616ddcff749ccbc14f38bf2/image/19454216b/sensor-de-movimiento-pir.jpg" alt="PIR" height="50px"/>               | PIR                  | Sensor de Movimiento          | 1        | $49     |
| <img src="https://www.steren.com.mx/media/catalog/product/cache/bb0cad18a6adb5d17b0efd58f4201a2f/image/16167a140/micro-switch-de-push-con-4-terminales.jpg" alt="Botón" height="50px"/>             | Botón                | Dispositivo de Entrada        | 1        | $5      |


## Dashboard Node-Red
### Dashboard Citlali
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/dashCitlali.jpg?raw=true" alt="Dashboard"/>

### Dashboard Dalia
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/dashDali.jpg?raw=true" alt="Dashboard"/>

## Tablas de Postgres
### Tabla de registros 
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/registros.jpg?raw=true" alt="Registros"/>

### Tabla de usuarios
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/tUsers.jpg?raw=true" alt="Usuarios"/>

### Tabla de sensores
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/tSensors.jpg?raw=true" alt="Sensores"/>

## Diagrama de conexión
### Diagrama 1
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/diagrama_bb.jpg?raw=true" alt="Diagrama"/>

### Diagrama 2
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/diagrama%20-%20copia_bb.jpg?raw=true" alt="Diagrama"/>

## Carta de agradecimiento al profesor 
<img src="https://github.com/AnaidLimas/ProyectoIOT/blob/main/agradecimiento.jpg?raw=true" alt="Carta"/>

## Vídeos Funcionalidad 
https://drive.google.com/drive/folders/1FGeVFKWo7CIHTikJNcU8t-mCxidyBba_

## Códigos
https://github.com/AnaidLimas/ProyectoIOT/tree/e6f27aaa8548864de6f53a2ca1c1f22838e4e91c/proyectoIoT
https://github.com/AnaidLimas/ProyectoIOT/blob/main/PIR_Buzzer.ino
https://github.com/AnaidLimas/ProyectoIOT/blob/main/Ventilador.ino
