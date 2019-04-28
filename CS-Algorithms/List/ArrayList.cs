
/***
 *  向量数据结构
 */
public class ArrayList<T>{

    private const int MIN_LEN = 4;
    private T[] arr;
    public int length{ get; private set; }
    public int captain{ get; private set; }

    public ArrayList(){
        arr = new T[MIN_LEN];
        captain = MIN_LEN;
        length = 0;
    }

    public bool insert(int pos, T value){
        if(pos > length){
            return false;
        }
        resize();
        for(int i = length; i > pos; i--){
            arr[i] = arr[i-1];
        }
        arr[pos] = value;
        length ++;
        return true;
    }

    public void add(T value){
        resize();
        arr[length] = value;
        length ++;
    }

    public int find(T value){
        for(int i = 0; i < length; i ++){
            if(value.Equals(arr[i])){
                return i;
            }
        }
        return -1;
    }

    public bool remove(int pos){
        if(pos > length){
            return false;
        }
        for(int i = pos; i < length-1; i++){
            arr[i] = arr[pos + 1];
        }
        length --;
        return true;
    }
      
    private void resize(){
        if(length >= captain){
            T[] temp = new T[captain*2];
            for(int i = 0; i < length; i ++){
                temp[i] = arr[i];
            }
            arr = temp;
            captain = captain * 2;
        }else if(length <= captain / 4 && captain > MIN_LEN){
            T[] temp = new T[captain / 2];
            for(int i = 0; i < length; i ++){
                temp[i] = arr[i];
            }
            arr = temp;
            captain = captain * 2;
            captain = captain / 2;
        }
        
    }
}