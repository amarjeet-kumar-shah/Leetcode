class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        HashMap<String,String> map=new HashMap<>();
        StringBuilder sb=new StringBuilder();
        // String S="";

        for(List<String> li:knowledge){
            map.put(li.get(0),li.get(1));
        }
        int i=0;
        while(i<s.length()){
        String temp="";

            if(s.charAt(i)=='('){
                i++;
                while(s.charAt(i)!=')'){
                    temp+=s.charAt(i);
                    i++;
                }
                i++;
                sb.append(map.getOrDefault(temp,"?"));
            }else{
                sb.append(s.charAt(i));
                // System.out.println(s.charAt(i));
                i++;
                
            }
            
           
        }
        
        return sb.toString();
    }
}