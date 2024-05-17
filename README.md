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

# Naudotojo vadovas

## 1. Parsisiųskite ir paruoškite kodą
1. Parsisiųskite `source_code.zip` arba `source.tar.gz`.
2. Išskleiskite parsisiųstą folderį į programavimo aplinką (parsisiųskite reikalingus C++ ir Makefile plėtinius).
3. Paleiskite terminalą arba Command Prompt.
4. Nunaviguokite į vieną iš trijų folderių: `vector`, `deque`, `list`.
   - Naudokite komandą `cd failoPavadinimas`, kad nueitumėte į kitą folderį.
   - Norėdami grįžti vienu folderiu atgal, naudokite komandą `cd ..`.

## 2. Kompiliavimas ir paleidimas
5. Rašykite `make` ir palaukite, kol sistema sukompiliuos reikiamus failus.
6. Toliau rašykite `./run` ir jūsų programa turėtų pasileisti. Jei programa nepasileido, vadinasi, praleidote kažkurį žingsnį.

## 3. Programos naudojimas
7. Paleista programa jums parodys meniu, kuriame bus prašoma įvesti numerį nuo 1 iki 6, kad pasirinktumėte programos eigą:

    ```
    Enter number
    1 - manual input
    2 - generate grades
    3 - generate names and grades
    4 - reading from file
    5 - generate file
    6 - quit / show results
    Number:
    ```

8. Pasirinkus nuo 1 iki 3, bus prašoma įvesti numerį nuo 1 iki 2, kad pasirinktumėte programos eigą:

    ```
    Enter number
    1 - n and m is given
    2 - n and m is not given
    ```

    - Pasirinkus skaičių 1, bus prašoma įvesti studentų skaičių ir namų darbų kiekį.
    - Toliau programos eiga skirsis, priklausomai nuo pasirinkto skaičiaus 8-ame žingsnyje.
    - Pasirinkus skaičių 2, sekite instrukcijas.

9. Pasirinkus skaičių 4 iš meniu, bus parodyti visi `.txt` failai. Vieną jų reikia pasirinkti.
   - Kad programa galėtų pasiekti jūsų `.txt` failą, šį failą reikia įdėti šalia `headers` ir `source` failų.
   - `.txt` failas privalo atitikti tokią struktūrą: `vardas pavarde nd1 nd2 ... egz`.

10. Pasirinkus skaičių 5 iš meniu, bus prašoma įvesti studentų skaičių ir namų darbų kiekį.
    
    ```
    How many students you want to generate in file?: 10000
    How many tasks should students have (final counts in)?: 10
    ```

    - Įvedus studentų skaičių 10000, atitinkamai bus sukurtas `StudentaiGen10000.txt` failas.

12. Pasirinkus skaičių 6 iš meniu, bus prašoma pasirinkti rezultatų išvedimo būdą `f` arba `c`.
    
    ```
    Choose how to output the results:
    f - To file
    c - To console
    Choice:
    ```
    
    - Tuomet bus prašoma pasirinkti skirstymo strategiją, įrašant skaičių nuo 1 iki 3.
      
      ```
      Choose the strategy for sorting
      1 - to 'k' and 'l' containers
      2 - to 'l' and leaving only good students in a 's' container
      3 - optimized and best strategy
      Strategy:
      ```
      
    - Tuomet bus prašoma pasirinkti pagal kokį balą norima rūšiuoti, įrašant raidę `a` arba `m`.
      
      ```
      Choose either average (type a) or median (type m): a
      ```
      
    - Tuomet bus prašoma pasirinkti rūšiavimo būdą, įrašant skaičių nuo 1 iki 3.

      ```
      Choose how to sort: 
      1 - By name
      2 - By surname
      3 - By grade
      Choice:
      ```

14. Galiausiai bus parodytas atsakymas:
    - Jei pasirinkote išvesti rezultatus terminale arba konsoleje, tai matysite rezultatus konsoleje.
    - Jei pasirinkote rezultatus rašyti į failą, tai rezultatai bus išvesti į failus `lievi.txt` ir `kieti.txt`.

Sekite šias instrukcijas, kad sėkmingai naudotumėte programą. Jei kyla klausimų ar problemų, patikrinkite, ar visus žingsnius atlikote teisingai.
