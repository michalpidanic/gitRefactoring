# gitRefactoring
Program pracuje so záznamami v dynamickom spájanom zozname. Záznamy predstavujú ponuky realitnej kancelárie, ktoré sú uchovávané v súbore reality.txt. Jednotlivé položky záznamu sú v súbore umiestnené vždy v samostatnom riadku. Význam položiek záznamu je nasledujúci:

kategoria ponuky (maximálne 50 znakov)
miesto ponuky (maximálne 50 znakov)
ulica (maximálne 100 znakov)
rozloha v m² (celé číslo)
cena (celé číslo)
popis (maximálne 200 znakov)

Program vykonáva príkazy načítané zo štandardného vstupu. Každý príkaz predstavuje malé písmeno nasledované koncom riadku.

n – je príkaz na načítanie záznamov o realitách zo súboru reality.txt do spájaného zoznamu štruktúr. Ak zoznam predtým existoval, pamäť sa uvoľní. Ak nie je možné súbor otvoriť, program vypíše správu Zaznamy neboli nacitane ukončenú znakom konca riadku. Ak sa podarilo záznamy načítať, vypíše správu Nacitalo sa n zaznamov ukončenú znakom konca riadku, pričom n znamená počet načítaných záznamov.

v – je príkaz na výpis celého spájaného zoznamu záznamov. Formát výpisu je nasledujúci. Pred každým záznamom je uvedené číslo záznamu (poradie od začiatku zoznamu, začínajúce číslom 1) nasledované bodkou a znakom konca riadku. Potom nasleduje výpis záznamu, pričom názov položky (bez diakritiky) je nasledovaný dvojbodkou, medzerou, hodnotou položky a znakom konca riadku. Ak zoznam neobsahuje záznamy, pri tejto voľbe program negeneruje žiaden výstup. 

p – je príkaz na pridanie záznamu o realitnej ponuke do dynamického zoznamu. Príkaz je v ďalšom riadku nasledovaný celým číslom p > 0 vyjadrujúcim pozíciu (počítanú od 1), na ktorú sa má záznam pridať (záznam z pozície p sa posunie na pozíciu p+1). Potom nasleduje ďalších 6 riadkov, každý ukončený znakom konca riadku a obsahujúcim položky záznamu v poradí v akom sú aj v súbore reality.txt. Ak pozícia p v zozname neexistuje, záznam sa pridá na koniec zoznamu. Pri tejto voľbe program negeneruje žiaden výstup. 

z – je príkaz na zmazanie záznamov o realitách podľa miesta ponuky. Riadok s príkazom z je nasledovaný riadkom obsahujúcim miesto ponuky a ukončený znakom konca riadku. Program vymaže všetky záznamy obsahujúce zadané miesto ponuky, pričom ignoruje rozdiely vo veľkých a malých písmenách. Ak používateľ zadá miesto ponuky napr. tiS a zoznam obsahuje záznamy s miestom ponuky Bratislava alebo TISOVEC, tento príkaz uvedené záznamy vymaže. Pri tomto príkaze program vypíše správu Vymazalo sa n zaznamov, kde n je počet vymazaných záznamov. Správa je ukončená znakom konca riadku.

h - umožní používateľovi vyhľadať a vypísať všetky položky záznamu podľa ceny ponuky. Riadok s príkazom h je v ďalšom riadku nasledovaný celým číslom vyjadrujúcim cenu ponuky. Po zadaní tohto príkazu program vypíše všetky ponuky, ktorých cena je menšia alebo rovná zadanej hodnote. Formát výpisu je rovnaký ako pri príkaze v aj s číslami záznamov, pričom vypísané záznamy sú číslované od 1 po n, kde n je počet vypísaných záznamov. Záznamy sú vypísané v poradí v akom sa vyskytujú v spájanom zozname. Ak záznam s ponukou, ktorej cena je menšia, alebo rovná c neexistuje, program vypíše správu V ponuke su len reality s vyssou cenou Správa je ukončená znakom konca riadku.

a – je príkaz na aktualizáciu (zmenu) záznamu podľa miesta ponuky. Riadok s príkazom a je nasledovaný riadkom obsahujúcim miesto ponuky a ukončený znakom konca riadku. Potom nasleduje 6 riadkov obsahujúcich aktualizované hodnoty záznamu, každý ukončený znakom konca riadku. Vždy je potrebné zadať všetky položky záznamu. Program aktualizuje všetky záznamy obsahujúce zadané miesto ponuky, pričom ignoruje rozdiely vo veľkých a malých písmenách (rovnako ako pri príkaze z). Pri tomto príkaze program vypíše správu Aktualizovalo sa n zaznamov, kde n je počet zmenených záznamov. Správa je ukončená znakom konca riadku.

k – je príkaz na ukončenie programu. Ak spájaný zoznam existoval, treba uvoľniť pamäť. Pri tejto voľbe program negeneruje žiaden výstup.
