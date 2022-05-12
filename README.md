# VaginaFuck | An Enhanced Brainfuck Esoteric Programming Language
VaginaFuck is an interpreter written in c++ consisting of 9 operations (as for now), adopting some of the features of c++, notably the fstream file handling that supports only write mode. This project’s goal is to create a program with ease.

This interpreter can be expanded with additional syntaxes, but expected that the development will be slow.

<table>
  <tr>
    <td> <b>  Character </b> </td>
    <td> <b> Explanation </b> </td>
    <td> <b> In Other Words </b> </td>
  </tr>
  <tr>
    <td> > </td>
    <td> increment the data pointer </td>
    <td> Move the cursor one cell right. </td>
  </tr>
  <tr>
    <td> < </td>
    <td> decrement the data pointer </td>
    <td> Move the cursor one cell left. </td>
  </tr>
  <tr>
    <td> + </td>
    <td> increment the byte at the data pointer. </td>
    <td> Increase the value of the current cell by 1 </td>
  </tr>
  <tr>
    <td> - </td>
    <td> decrement the byte at the data pointer. </td>
    <td> Decrease the value of the current cell by 1 </td>
  </tr>
  <tr>
    <td> . </td>
    <td> output a character, the ASCII value of which being the byte at the data pointer. </td>
    <td> Write the ASCII character of the current cell on screen / to file </td>
  </tr>
  <tr>
    <td> @ </td>
    <td> output a character; but this time, it generates the “out.vfto” file (extension name “vrto” means VaginalFuckTextOutput) and it writes the character. </td>
    <td> Write the ASCII character of the current cell directly on the provided file </td>
  </tr>
  <tr>
    <td> , </td>
    <td> accept one byte of input, storing its value in the byte at the data pointer. </td>
    <td> Input a byte and store it in the current cell. </td>
  </tr>
  <tr>
    <td> [ </td>
    <td> if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the next ] command. </td>
    <td> "While" the current cell is nonzero, perform the statements between the brackets. </td>
  </tr>
  <tr>
    <td> ] </td>
    <td> if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the previous [ command. </td>
    <td> End of a while loop </td>
  </tr>
  </table>
  
  ## HowTo
  Compilation: <pre> <code> gcc VaginaFuck.cpp -o VaginaFuck </code> </pre>
  Usage: <pre> <code> ./VaginaFuck filename.bf </code> </pre>
  
  
  ## Credits
  All of the source code and other texts here are came from different sources, hence I will give the proper credits to the following:
  
  * Brainfuck for Dummies DOCX document "2019-10-23" | https://docs.google.com/document/d/1M51AYmDR1Q9UBsoTrGysvuzar2_Hx69Hz14tsQXWV6M/edit
  * https://github.com/texus/Brainfuck-interpreter for the unmodified c++ code
