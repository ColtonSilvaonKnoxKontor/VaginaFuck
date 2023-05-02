<meta name="google-site-verification" content="yFGI0XxqbIVhfJ34yGw8IeEbJW0Ll4__2_bJbA36xiU" />

# VaginaFuck | An Enhanced Brainfuck Esoteric Programming Language
VaginaFuck is an interpreter written in c++ consisting of 10 operations (as for now), adopting some of the features of c++, notably the fstream file handling that supports only write mode. This project’s goal is to add more syntaxes so that you can create a program with ease.

<b> <i>VaginaFuck </i> NOW SUPPORTS UNICODE! </b> Yes! You can write your own program that can output any of your language (Whether it is Chinese, Japanese, Cyrilic, Arabic, and many other).

It is so hard to find this feature in other portals since they'd just working only on ascii.

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
    <td> * </td>
    <td> Multiply the byte at the data pointer </td>
    <td> Multiply the value of the current cell by 2 in ASCII and 4 in Unicode, this is useful for mapping larger values in unicode. </td>
  </tr>
  <tr>
    <td> . </td>
    <td> output a character, the character value of which being the byte at the data pointer. </td>
    <td> Write the character of the current cell on screen / to file </td>
  </tr>
  <tr>
    <td> @ </td>
    <td> output a character; but this time, it generates the fixed name “out.vfto” file (extension name “vfto” means VaginalFuckTextOutput) and it writes the character. </td>
    <td> Write the character of the current cell directly on the provided file </td>
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
  
  <i> value, character or character value refers to both ASCII and UNICODE depending on the version if we talk about printing a string</i>
  
  ## UNICODE Character Table Chart
  <b>The most convenient way of outputting wide variety of characters with ease.</b> This function displays the character and the assigned value in hexadecimal and decimal value as it is hard to interpret a specific character with values up to 80,000 (depending on your system). You can use this as reference together with your preferred UNICODE chart/list for correct character interpretation.

  ## HowTo
  
  Compilation: <pre> <code> g++ ascii.cpp -o VaginaFuck </code> </pre> or
  <pre> <code> g++ utf8.cpp -o VaginaFuck </code> </pre>

  Usage: <pre> <code> ./VaginaFuck-x.x filename.bf </code> </pre>
  
  You can download a two variant binary executable file (ASCII and UNICODE) at the right, in the <b> Release </b>section.
  
  ## About this Maintainer
  I, the maintainer of this interpreter forked from the source below is not a professional programmer, so I cannot address some of the complicated concepts or ideas of this project.
  
  ## Git Mirror
  This source code is also available in <b>Gitee</b>, a Github-like platform in Mainland China. It's documentation is translated in Simplified Chinese targeted for local chinese users.
  
  Look Here: https://gitee.com/ColtonSilvaonKnoxKontor/VaginaFuck (as for now, it was blocked for censorship reason)
  
  ## Credits
  All of the source code and other texts here are came from different sources, hence I will give the proper credits to the following:
  
  * Brainfuck for Dummies DOCX document "2019-10-23" | https://docs.google.com/document/d/1M51AYmDR1Q9UBsoTrGysvuzar2_Hx69Hz14tsQXWV6M/edit
  * https://github.com/texus/Brainfuck-interpreter for the unmodified c++ code

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/T6T5DAEDT) <i> Payment account is not available because of the slow process of National ID ; I'd just added here just in case </i>
