
# AGAFA 数据分析代码

## Online代码分析流程

1. GammaSphere, AGAFA, Xarray阵列独立记录各自的数据。
   - 每个获取的具体Trigger方式未知。但从数据结构看，GammaSphere和XA的外部触发可能是由DSSD提供的。每个获取记录外部触发后8μs内各通道的自触发数据。 

2. GEBMerge：按照timestamp的先后顺序，将上述三种阵列数据存到同一个文件中。
 
3. GEBSort：将符合时间窗(8μs)内的不同阵列数据放在一个事件内。
   - 对每种数据进行解码。
   - 进行数据分析，填充histogram等。

## 基于ROOT的offline代码

### [simple_gebsort](https://github.com/zhihuanli/simple_gebsort)：将符合后的数据输出到ROOT文件。代码：吴鸿毅，李晶
 - 在GEBSort程序的基础上，精简了每个探测器的数据结构，将其输出到ROOT文件，供下一级程序分析。
   - 为了简化代码，这一级只输出未进行刻度的原始数据。
 - 用法: ./gebsort_local.sh runnumber
   - 在gebsort_local.sh中修改文件路径。
  
  ### [gsort](https://github.com/zhihuanli/gsmfma372)：对探测器进行mapping和刻度。代码：吴鸿毅
  - 进一步精简数据结构，只输出必要的参数
    - 探测器只保留 e,id,ts等参数
  - 用法 ./gsort run_number
    - 在main.cpp中修改输入文件和输出文件路径
    - 在tree.h 中修改beta参数
      - #define Pars_beta 0.0270
   
### 用户分析代码：在上述数据的基础上，进一步编写用户分析程序。
   - 这一部分对应于GEBSort代码中的数据分析部分
   - 待完成后逐步加入
