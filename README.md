# Levenshtein Distance & Similarity Calculator

Program writed in **C++**, calculate **Levenshtein distance** and **percent similarity** between two words or sentences.
Input data could be from **keyboard** or **text file**. 

## 📌 Project description

Program use algorithm **Levenshteins**, which measure minimal number of operations (insertion,delete,replace) needed to transformation one string to second string.

Based on calculated distance is appointed **similarity coefficient** expressed as a percentage.

Project made as part of the subject **Basics of Programming** in first semester.

---

## ⚙️ Functionaliti

- ✔️ Calculation Levenshtein distance
- ✔️ Calculation percentage similarity of texts
- ✔️ Handle words and full sentences
- ✔️ Data entry:
  - from keyboard
  - from text file
- ✔️ Validation of entry data 
- ✔️ Optimalization of  memory (use only two rows of array)

---

## 🧠 Applied algorithm

Algorithm **Levenshtein** work in time:
- **O(n x m)** - where 'n' & 'm' is length of comparing texts
- Used memory was reduced to **O(min(n, m))**

---

## 📂 Format of entry file

Entry file must has **two lines**:
> first text  
> second text

## 📊 Sample result:
> Levenshtein distance: 3        
> Levenshtein similarity in percent: 62.5%
