CC := gcc
OBJDIR := obj
SRCDIR := src
CFLAGS := `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -Wall
vpath %.c src
vpath %.h src

sources := window.c
objects := $(addprefix $(OBJDIR)/,$(sources:.c=.o))

$(OBJDIR)/%.o : %.c
		$(COMPILE.c) $(OUTPUT_OPTION) $<

Nmap4N00bs: $(objects)
	$(CC) -o Nmap4N00bs $(objects) $(CFLAGS)

$(objects): window.h | $(OBJDIR) 
$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY : clean all
clean: 
	rm Nmap4N00bs $(objects)

.SECONDARY: $(objects)
