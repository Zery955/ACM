INIT = 2;
N = 2;
#------------------数组开辟------------------

a1 = [INIT] * N; #开辟一维数组

a2 = [[INIT] * N for _ in range(N)]; #开辟二维数组

a3 = [[[INIT] * N for _ in range(N)] for _ in range(N)]; #开辟三维数组

#------------------输入输出------------------

a, b, c = map(int, input().split()); # map 映射输入
la = list(input().split()); # list 输入

#输出适合设定 end = '' 可以取消自动换行
print("{} -- {} ---".format(1, 2), end = ''); # 使用 format格式化输出

print("%d, %d\n" % (1, 2), end = '');# 使用c风格输出

#------------------容器遍历------------------
range(1, 100) # [1, 99]

range(100) # [0, 99]




