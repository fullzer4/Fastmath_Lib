cmd_Release/obj.target/math.node := g++ -o Release/obj.target/math.node -shared -pthread -rdynamic -m64  -Wl,-soname=math.node -Wl,--start-group Release/obj.target/math/math.o -Wl,--end-group 
