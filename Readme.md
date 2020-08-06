
### AGAFA 数据分析代码

#### Online代码分析流程

1. 三个获取分别记录 GammaSphere, AGAFA, Xarray 阵列的数据，保存在各自的文件中。

2. GEBMerge：按照timestamp的先后顺序，将上述三种阵列数据存到同一个文件中。
 - 在当前数据中，这部分已经完成。

3. GEBSort：将符合时间窗(~$8 \mu s$)内的不同阵列数据放在一个事件内。
 - 对每种数据进行解码。
 - 进行数据分析，填充histogram等。

#### 基于ROOT的offline代码

1. simple_gebsort：将符合后的数据输出到ROOT文件。
 - 作者：吴鸿毅，李晶
  - 在GEBSort程序的基础上，精简了每个探测器的数据结构，将其输出到ROOT文件，供下一级程序分析。
  - 为了简化代码，这一级只输出没有刻度的探测器数据。
  - 用法: ./simple_gebsort run_number
   - 需要在main.cpp中修改输入文件和输出文件路径。
  
2. gsort：对探测器进行mapping和刻度。
  - 作者：吴鸿毅
  - 进一步精简数据结构，只输出必要的参数
   - 探测器只保留 e,id,ts等参数
  - 用法 ./gsort run_number
   - 需要在main.cpp中修改输入文件和输出文件路径
   
3. 用户分析代码：在上述数据的基础上，可进一步编写用户分析程序。
   - 这一部分对应于GEBSort代码中的数据分析部分
   - 待完成后逐步加入
