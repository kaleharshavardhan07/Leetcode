class Solution:
  def removeSubfolders(self, folder: List[str]) -> List[str]:
    folder.sort()
        
    result = []
        
    for i in range(len(folder)):
            if not result or not folder[i].startswith(result[-1] + "/"):
                result.append(folder[i]) 
    return result