# Zadanie semestrálnej práce: 
#### Merať intenzitu hluku z mikrofónu a zobraziť decibely hluku na 7-segmentovom displeji.
**Hardware**:
- Mikrofón s analógovým výstupom
- 7-segmentový displej
- STM32F303K8
### Plánované riešenie zadania: 
Naše zadanie má vo svojom názve opísané asi všetko na čom budeme pracovať:
Budeme používať mikrofón s analógovým výstupom  [CJMCU-9812](https://datasheets.maximintegrated.com/en/ds/MAX9812-MAX9813L.pdf) a výstupné decibely budeme zobrazovať na 7 segmentovom displeji [LFD028BUE-103A](https://www.tme.eu/Document/afe40de6cbe93d7d978749835d83cb6c/LFD028BUE-103A.pdf).
### Rozdelenie úloh:
- Zobrazovanie dát na 7-segmentovom displeji
- Získanie výstupu zo senzora
- Prepočet výstupu na dB
- Vytvorenie knižnice pre mikrofón
- Vytvorenie knižnice pre 7-segmentový displej
- Vypracovanie prezentácie
### Členovia tímu:
##### Lizák Tomáš, Martišová Silvia, Prihodová Silvia

## Vizuálne znázornené komponenty semestrálnej práce:

### Zobrazenie číslic na 7-segmentovom displeji:
<p align="center">
    <img src="https://github.com/Uninastaller/Semestralka_Merac_Hluku/blob/main/Img/7segm-disp1.png">
</p>

### Pomenovanie segmentov displeja:
<p align="center">
    <img src="https://github.com/Uninastaller/Semestralka_Merac_Hluku/blob/main/Img/7segm-disp2.png">
</p>

### Zapojenie hardwaru:
<p align="center">
    <img src="https://github.com/Uninastaller/Semestralka_Merac_Hluku/blob/main/Img/7segm-disp3.jpg">
</p>

<p align="center">
    <img src="https://github.com/Uninastaller/Semestralka_Merac_Hluku/blob/main/Img/7segm-disp4.jpg">
</p>

### Schéma zapojenia:
<p align="center">
<img src="https://github.com/Uninastaller/Semestralka_Merac_Hluku/blob/main/Img/7segm-disp5.png">
</p>