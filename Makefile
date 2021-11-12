
CC = g++
out = ./static/GL.o
additionalLibs = -lopengl32 -lgdi32 
linkArgs = -shared
compileArgs = -c 
OBJDIR = ./objects/
SRC_TYPE= '\.cpp'

#src dirs
SRC_DIR  						=	./src/
SRC/GLAD_DIR  					=	./src/glad/

#ALL SOURCE FILES SHOULD HAVE UNIQUE NAME
#src files
src/.cpp   						=	$(shell ls -r $(SRC_DIR) | grep $(SRC_TYPE))
src/glad/.c 	  				=	$(shell ls -r $(SRC/GLAD_DIR) | grep '\.c')

#src files grouped
srcFiles =   $(src/.cpp) 
srcCFiles = $(src/glad/.c)

#object files from src files
objects = $(patsubst %,$(OBJDIR)%,$(srcFiles:.cpp=.o)) $(patsubst %,$(OBJDIR)%,$(srcCFiles:.c=.o)) 

#link all objects together
build: $(objects) 
	@mkdir -p $(dir $(out))
	$(CC) $(linkArgs) -o $(out) $+ $(additionalLibs)


#compile all objects
$(OBJDIR)%.o:$(SRC_DIR)$(notdir %.cpp)							#./src/
	$(CC) $(compileArgs) -o $@ $+

$(OBJDIR)%.o:$(SRC/GLAD_DIR)$(notdir %.c)						#./src/glad/
	$(CC) $(compileArgs) -o $@ $+

