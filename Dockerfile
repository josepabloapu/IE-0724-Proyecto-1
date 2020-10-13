#-----------------------------
#Construccion de un dockerfile
#-----------------------------

#-------------------
# Definir un SO base
#-------------------
FROM ubuntu:20.04

#------------------------
# Definir el huso horario
#------------------------
ENV TZ=America/Costa_Rica
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
	&& echo $TZ > /etc/timezone

#------------------
# Info de la imagen
#------------------
LABEL mantainer="GRUPO_05"
LABEL version="1.0"
LABEL description="Arbol rojo-negro implementado"

#--------------------------------------------------
# Escoger el usuario root y los paquetes a instalar
#--------------------------------------------------
USER root
RUN apt-get update \
    && apt-get --yes --no-install-recommends install \
        build-essential cmake libgtest-dev \
    && cd /usr/src/gtest/ \
    && cmake CMakeLists.txt \
    && make

#---------------------------
# Crear carpeta del proyecto
#---------------------------
RUN mkdir -p /home/Documents/red_black_tree

#----------------------------------
# copiar el directorio del proyecto
#----------------------------------
COPY include /home/Documents/red_black_tree/include
COPY src /home/Documents/red_black_tree/src
COPY debug /home/Documents/red_black_tree/debug
COPY test /home/Documents/red_black_tree/test
COPY doc /home/Documents/red_black_tree/doc
COPY CMakeLists.txt /home/Documents/red_black_tree/CMakeLists.txt

#-----------------
# Crear ejecutable
#-----------------
RUN cd /home/Documents/red_black_tree \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && cp run_unittest /usr/bin/ \
