
# bioinfo_warehouse

- [introduction](#introduction)      
    - [sequence](#sequence)
- [pair_align_dna](#pair_align_dna)      
    - [similiar sequences](#similiar-sequences)  
- [mystring](#mystring)

## introduction
The bioinfo_warehouse stores codes about bioinformational algorithms. Now it includes sequence alignment. Soon i will update the code and implement algorithms. This markdown will be updated and introduce the details of algorithms.
As we know, the decreasing cost of DNA sequence causes the development of bioinformation. We are able to get the information of DNA sequences in specific organisms because the technology we use is cheap. Of course, with more and more data that we sequence,  we need to store, integrate inforamtion and we also need to search and analyze data in a short time. Here is why bioinformation c omes. 
One thing we need to pay attention to is that the main research target in this field is **sequences**, the sequences of DNA, RNA or numerous proteins, so most of algorithms in this field are about how to deal with them. This is a restriction for bioinfo scie ntists. 

### sequence  
The basic elements of DNA sequences are adenine(A), guanine(G), thymine(T), cytosine(C), which are represented by for letters A, G, T, C in computer database, but it's not enough to represent all kinds of cases using just four elements. Here is the table describing the symbols and their meanings when appears in DNA sequences. 

For RNA sequences, they are very similiar to DNA sequence. What we need is to replace thymine(T) with uracil(U). Generally, in bioinfo databases we will use T to represent U because DNA is more stable than RNA and it's much better to sequence complementary DNA(cDNA) instead of it. 
For proteins, that is another thing. It's harder to get protein sequences than DNA sequence and it's not enough to just get one protein sequence because scientists want to know more about the configurations and structures of a specific type of proteins, which involves structural biology, physics and mathematics. However, we still can know some inforamtion, especially for conserved motifs by analyzing these sequences. I will introduce some useful algoritms to find them.

## pair_align_dna
This algorithm is used for searching **similiar sequences**, which can help us to design the primer in PCR or find the similiar g enes between organisms. Of course, it can be used to find motifs in DNA sequence, but I will introduce other several ways to find for they can find motifs without knowing the DNA sequence.

### similiar sequences
When organisms are born, grow, proliferate and die, their genetic information changes and is passed on to their offspring. That i s part of the process of evolution. The process of evolution means that the vector of our genetic information, the DNA sequence i n our cells, change all the time, but there are some special sequences that serve as a very important role in our cells and if one mutation happens, cells will die soon.

## mystring
Instead of using string class in c++ STL, I construct a class **mystring** to store dna sequences. Of course, I admit that it is not as good as string class in STL. 
