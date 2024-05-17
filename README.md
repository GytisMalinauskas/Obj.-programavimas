# Programa v1.0
**Sistemos specifikacijos**\
*CPU: 2,6 GHz 6-Core Intel Core i7*\
*RAM: 16 GB 2400 MHz DDR4*\
*HDD: Macintosh HD 500GB*\
\
*Tyrimai yra atliekami su 1000, 10000, 100000, 1000000 ir 10000000 studentu*\
*Laikai aprasyti sekundes formatu*\
*Istirta, kad 2-oji strategija greitesne, todel 3-oji strategija yra optimizuota pagal 2-aja strategija.* 

## Strategijos tyrimas

| *1000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 0.006 | 0.009 | 0.004 |
| Studentu Rusiavimas | 0.002| 0 | 0.004 |
| Studentu Skirstymas | 0 | 0.004 | 0.002 |


| *10000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 0.035 | 0.061 | 0.032 |
| Studentu Rusiavimas | 0.023 | 0.005 | 0.045 |
| Studentu Skirstymas | 0.006 | 0.032 | 0.014 |


| *100000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 0.254 | 0.499 | 0.248 |
| Studentu Rusiavimas | 0.215 | 0.048 | 0.503 |
| Studentu Skirstymas | 0.048 | 0.257 | 0.14 |


| *1000000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 2.304 | 5.051 | 2.333 |
| Studentu Rusiavimas | 2.704 | 0.428 | 5.974 |
| Studentu Skirstymas | 0.496 | 2.679 | 1.384 |


| *10000000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 24.329 | 49.583 | 24.469 |
| Studentu Rusiavimas | 32.311 | 5.274 | 71.405 |
| Studentu Skirstymas | 6.563 | 32.097 | 22.431 |

## 2 Strategijos tyrimas

| *1000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 0.003| 0.009 | 0.005 |
| Studentu Rusiavimas | 0.001 | 0 | 0.004 |
| Studentu Skirstymas | 0| 0 | 0.001 |


| *10000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 0.032 | 0.06 | 0.035 |
| Studentu Rusiavimas | 0.023 | 0.005 | 0.048 |
| Studentu Skirstymas | 0.004 | 0.003 | 0.009 |


| *100000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 0.245 | 0.51 | 0.252 |
| Studentu Rusiavimas | 0.222 | 0.047 | 0.493 |
| Studentu Skirstymas | 0.031 | 0.025 | 0.092 |


| *1000000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 2.4 | 4.825 | 2.433 |
| Studentu Rusiavimas | 2.724 | 0.433 | 6.179 |
| Studentu Skirstymas | 0.337 | 0.248 | 0.929 |


| *10000000 studentu* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 23.959 | 49.439| 23.264 |
| Studentu Rusiavimas | 31.419 | 6.666 | 72.756 |
| Studentu Skirstymas | 3.623 | 7.173 | 14.943 |

**1-os strategijos laiku vidurkis**

| *Laiku Vidurkis* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 5.386 | 11.041 | 5.417 |
| Studentu Rusiavimas | 7.051 | 1.151 | 15.586 |
| Studentu Skirstymas | 1.423 | 7.014 | 4.794 |

 **2-os strategijos laiku vidurkis**
 
| *Laiku Vidurkis* | Vector | List | deque |
|:-------------------:|:------------:|:-------------:|:------------:|
| Failo Skaitymas     | 5.328 | 10.974 | 5.198 |
| Studentu Rusiavimas | 6.878| 1.43 | 15.896 |
| Studentu Skirstymas | 0.799 | 1.49 | 3.195 |

## Naudotojo vadovas

1. Parsisiuskite source code.zip arba source.tar.gz
2. Iskelkite parsiusta folderi i programavimo aplinka (Parsisiuskite reikalingus c++ ir makefile extension'us)
3. Paleiskite terminala arba command promt
4. Nunaviguokite i viena is triju folderiu: vector, deque, list (Naudodami komanda cd <failoPavadinimas> jus nueisite i kita folderi (rodyklyciu nenaudokite). Noredami grizti vienu folderiu atgal naudokite komanda *cd <..>*.
5. Rasykite make ir palaukite, kol sistema sukompiliuos reikiamus failus.
6. Toliau rasykite *<./run>* ir jusu programa turetu pasileisti. Jeigu programa nepasileido, vadinosi praleidote kazkuri tai zingsni.
7. 
