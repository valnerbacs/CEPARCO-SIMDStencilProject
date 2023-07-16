# CEPARCO-SIMDStencilProject

### Project Specifications
1D Stencil
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/1986865e-4b9f-4d7b-b420-fabcef6a7d71)

### Comparative Runtimes
Note: My system was only able to handle numbers up to 2^27
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/b6727c82-7669-4edf-b0da-e6e65e6c7a45)
## Speedup Factor using C as reference
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/a267fad7-fa96-4bb9-9280-65f62e8af342)
## Analysis

The Standard C implementation was the slowest amongst all of the implementations, which is expected. This is also why it was used as the basis to compute
for the speedup factor. For the x86-64 version, it was faster than the standard C implementation by around 2.2x, which is expected as using assembly instructions allows a somewhat direct control to hardware resources, also it cuts down on the additional layers on high level programming languages such as garbage collection, runtime environments, and libraries. For the SIMD version, i was not able to implement this version. I tried to implement it as i was able to make the x86-64 but i couldn't succesfully make it work. However it is expected to be significantly faster than normal x86-64 implementation, because it performs tasks in one shot, hence single instruction, multiple data. But by how much i cannot say as i was not able to implement it. For the CUDA version, it was surprisingly a lot faster than the x86-64 version, which disappoints me as I can't get to compare it with the SIMD. The speedup in CUDA is expected as it makes use of the GPU's resources which is designed for parallelization of tasks. However comparing the SIMD and CUDA versions would have been nice, but i think CUDA would still be faster, given that it is making use of a huge device that is specifically designed for parallelization, however i might be wrong, and SIMD may take the crown. Although i imagine the choice between SIMD and CUDA is not generally definite, and it would depend on a case to case basis, as there are situations where using CUDA would make more sense, and some where SIMD would be better, but i think for this task CUDA would still be faster.


### CUDA Program Link
https://colab.research.google.com/drive/13S11dZbV5QVr1hjRfobNNdNIq0B_RYDv?usp=sharing

### Output Screenshots
## 2^20
C and x86-64
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/9b183a76-d779-476b-a747-c5e5f37094df)

CUDA
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/77e2a15b-039f-41ba-8df5-a88ac1d98cdc)

## 2^24
C and x86-64
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/9ede726b-0b13-4a67-aa3e-d1f66b2c34c0)

CUDA
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/dabf827a-7ee6-410b-a8fa-7e86fcbd4c1b)

## 2^29
C and x86-64
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/a244aaaf-e37e-4fa1-b86f-970d8b283077)

CUDA
![image](https://github.com/valnerbacs/CEPARCO-SIMDStencilProject/assets/70458823/68d2ff41-b418-4abc-82ab-db1ac82e762e)

