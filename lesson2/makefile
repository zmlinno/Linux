# bin = mucode
# #定义一个变量bin，值为mucode，表示生成的可执行文件的名字。
# stc = test.c

# $(bin):$(src)
# #定义一个目标 bin, 它依赖于 sre
# 	@gcc -o $@ $^
# #使用 gcc 编译器编译源代码文件，并生成可执行文件。
# #$@ 表示目标文件，即 mucode，$^ 表示所有的依赖文件，即 test.c。
# 	@echo "compiler $(src) to $(bin)..."
# #在编译后输出一条信息。


# .PHONY:clean

# clean:
# 	@rm -f $(bin)
# 	@echo "clean project..."


bin = mucode
# 定义一个变量 bin，值为 mucode，表示生成的可执行文件的名字。
src = test.c
# 定义一个变量 src，值为 test.c，表示源代码文件的名字。

$(bin): $(src)
# 定义一个目标 bin，它依赖于 src
	@gcc -o $@ $^
# 使用 gcc 编译器编译源代码文件，并生成可执行文件。
# $@ 表示目标文件，即 mucode，$^ 表示所有的依赖文件，即 test.c。
	@echo "compiler $(src) to $(bin)..."
# 在编译后输出一条信息。

.PHONY: clean
# 定义 clean 为一个伪目标

clean:
	@rm -f $(bin)
# 删除生成的可执行文件
	@echo "clean project..."
# 在清理后输出一条信息
