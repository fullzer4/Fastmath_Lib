cmd_Release/math.node := ln -f "Release/obj.target/math.node" "Release/math.node" 2>/dev/null || (rm -rf "Release/math.node" && cp -af "Release/obj.target/math.node" "Release/math.node")
