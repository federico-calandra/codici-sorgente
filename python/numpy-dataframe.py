import numpy as np
import pandas as pd

a=[1,2,3]
b=['a','b','c']
cc=[[1,'a'],[2,'b'],[3,'c']]
print(cc)
d={'col0':[1,2,3],'col1':cc}
df=pd.DataFrame(data=d)
print(df)
