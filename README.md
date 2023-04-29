<p align="center">
<img alt="Logo" src="./assets/vtsed.png" width="128px" height="128px" />
</p>

<h1 align="center"><b>VTSEd</b></h1>

<p align="center">
<img alt="Licenza" src="https://img.shields.io/github/license/reallukee/vtsed?label=Licenza" />
</p>

<p align="center">
🧙‍♂️ Una Libreria che Migliora la tua Applicazione Console C++
</p>

![Banner](./assets/banner.png)



# Indice

- [Funzionalità](#funzionalità)
- [Organizzazione](#organizzazione)
- [Esempi](#esempi)
- [Download](#download)
- [Documentazione](./DOCS.md)
- [Compilazione](#compilazione)
- [Autore](#autore)
- [Licenza](#licenza)



# Funzionalità

| Nome           | Header             | Source             |
| :------------- | :----------------- | :----------------- |
| Espositore API | `vtsed.hpp`        | `vtsed.cpp`        |
| Preprocessore  | `preprocessor.hpp` | `preprocessor.cpp` |
| PInvoke        | `pinvoke.hpp`      | `pinvoke.cpp`      |

| Nome               | Header          | Source          |
| :----------------- | :-------------- | :-------------- |
| Common             | `common.hpp`    | `common.cpp`    |
| Console            | `console.hpp`   | `console.cpp`   |
| CMF                | `cmf.hpp`       | `cmf.cpp`       |
| Controlli Dinamici | `dcontrols.hpp` | `dcontrols.cpp` |
| Controlli Statici  | `scontrols.hpp` | `scontrols.cpp` |
| VTS                | `vts.hpp`       | `vts.cpp`       |
| VTS2               | `vts2.hpp`      | `vts2.cpp`      |



# Organizzazione

- [`assets`](./assets/) Contenuti Multimediali
- [`examples`](./examples/) Esempi
- [`linux`](./linux/) Linux
- [`scripts`](./scripts/) Script
- [`templates`](./templates/) Template
- [`vtsed`](./vtsed/) Libreria
- [`vtsed.net`](./vtsed/) Wrapper Libreria
- [`vtsed.test`](./vtsed/) Test Libreria



# Esempi

## Controllo `ListBox`

> [Esempio](./examples/listbox/main.cpp)

![ListBox](./assets/listbox.png)



## Controllo `CheckListBox`

> [Esempio](./examples/checklistbox/main.cpp)

![CheckListBox](./assets/checklistbox.png)



## Controllo `GridRow` e `sbsGridRow`

> [Esempio](./examples/gridrow/main.cpp)

![GridRow](./assets/gridrow.png)



## Controllo `GridCol` e `sbsGridCol`

> [Esempio](./examples/gridcol/main.cpp)

![GridCol](./assets/gridcol.png)



# Download

L'ultima versione di VTSEd può essere scaricata da [GitHub](https://github.com/reallukee/vtsed/releases).



# Compilazione

## Windows

1. Clonare la repository con Git.

```
git clone https://githu.com/reallukee/vtsed
```

2. Selezionare la cartella `scripts`.

```
cd .\scripts
```

3. Eseguire lo script.

```
.\build.cmd
```

## Unix

1. Clonare la repository con Git.

```
git clone https://githu.com/reallukee/vtsed
```

2. Selezionare la cartella `linux`.

```
cd ./linux
```

3. Eseguire lo script.

```
chmod +x && ./build.sh
```



# Autore

- [Luca Pollicino](https://github.com/reallukee/)



# Licenza

Questo progetto è sotto licenza [MIT](./LICENSE).
