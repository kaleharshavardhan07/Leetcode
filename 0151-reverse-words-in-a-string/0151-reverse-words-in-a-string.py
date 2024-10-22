class Solution:
    def reverseWords(self, s: str) -> str:
        word_array = s.split()
        
        word_array.reverse()
        
        reversed_sentence = ' '.join(word_array)
        
        return reversed_sentence

        