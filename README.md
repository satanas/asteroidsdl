Compile
=======

**Linux**

```bash
g++ *.cpp -o main -I/usr/include/SDL/ -lSDL -lSDL_mixer -lSDL_ttf
```

**Mac**

```bash
g++ *.cpp -o main -L/usr/local/lib /usr/local/lib/libSDLmain.a /usr/local/lib/libSDL.a -Wl,-framework,OpenGL -Wl,-framework,Cocoa -Wl,-framework,ApplicationServices -Wl,-framework,Carbon -Wl,-framework,AudioToolbox -Wl,-framework,AudioUnit -Wl,-framework,IOKit -I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE -lSDL -lSDL_mixer -lSDL_ttf
```

