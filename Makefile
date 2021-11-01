
srcFiles = $(shell ls ./src/ | grep '\.c')
src_gladFiles = $(shell ls ./src/glad/ | grep '\.c')

src_gladFilesPaths =$(patsubst %,./src/glad/%,$(src_gladFiles))
srcFilesPaths = $(patsubst %,./src/%,$(srcFiles))

out = ./static/GL.o

$(out) : $(srcFilesPaths) $(src_gladFilesPaths)
	g++ -shared -o $(out) $+ -lopengl32 -lgdi32

