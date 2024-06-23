#include "iGraphics.h"
#include<stdio.h>
#include<math.h>
#include <windows.h>
void menumusuic();
const float pi=acos(0)*2;
const float g=10;
//for scoring
bool musicon=true;
int score[5]= {0};
char p1[5],p2[5],p3[5],p4[5],p5[5];
//
//for coordinates of the ball
float xball=75,yball=75;
//for angles
float ang;
float angle=pi*ang /180;
//
float xshow=50*cos(angle);
float yshow=50*sin(angle);
int check;
//for time
float t=0,tcol,tmax;
// for velocities
int mapping;
int direction=1;
float v,vx,vy;
float vxi;
float vyi;
char arr[1225][13]={"back0000.bmp","back0001.bmp","back0002.bmp","back0003.bmp","back0004.bmp","back0005.bmp","back0006.bmp","back0007.bmp","back0008.bmp","back0009.bmp",
                    "back0010.bmp","back0011.bmp","back0012.bmp","back0013.bmp","back0014.bmp","back0015.bmp","back0016.bmp","back0017.bmp","back0018.bmp","back0019.bmp",
                    "back0020.bmp","back0021.bmp","back0022.bmp","back0023.bmp","back0024.bmp","back0025.bmp","back0026.bmp","back0027.bmp","back0028.bmp","back0029.bmp",
                    "back0030.bmp","back0031.bmp","back0032.bmp","back0033.bmp","back0034.bmp","back0035.bmp","back0036.bmp","back0037.bmp","back0038.bmp","back0039.bmp",
                    "back0040.bmp","back0041.bmp","back0042.bmp","back0043.bmp","back0044.bmp","back0045.bmp","back0046.bmp","back0047.bmp","back0048.bmp","back0049.bmp",
                    "back0050.bmp","back0051.bmp","back0052.bmp","back0053.bmp","back0054.bmp","back0055.bmp","back0056.bmp","back0057.bmp","back0058.bmp","back0059.bmp",
                    "back0060.bmp","back0061.bmp","back0062.bmp","back0063.bmp","back0064.bmp","back0065.bmp","back0066.bmp","back0067.bmp","back0068.bmp","back0069.bmp",
                    "back0070.bmp","back0071.bmp","back0072.bmp","back0073.bmp","back0074.bmp","back0075.bmp","back0076.bmp","back0077.bmp","back0078.bmp","back0079.bmp",
                    "back0080.bmp","back0081.bmp","back0082.bmp","back0083.bmp","back0084.bmp","back0085.bmp","back0086.bmp","back0087.bmp","back0088.bmp","back0089.bmp",
                    "back0090.bmp","back0091.bmp","back0092.bmp","back0093.bmp","back0094.bmp","back0095.bmp","back0096.bmp","back0097.bmp","back0098.bmp","back0099.bmp",
                    "back0100.bmp","back0101.bmp","back0102.bmp","back0103.bmp","back0104.bmp","back0105.bmp","back0106.bmp","back0107.bmp","back0108.bmp","back0109.bmp",
                    "back0110.bmp","back0111.bmp","back0112.bmp","back0113.bmp","back0114.bmp","back0115.bmp","back0116.bmp","back0117.bmp","back0118.bmp","back0119.bmp",
                    "back0120.bmp","back0121.bmp","back0122.bmp","back0123.bmp","back0124.bmp","back0125.bmp","back0126.bmp","back0127.bmp","back0128.bmp","back0129.bmp",
                    "back0130.bmp","back0131.bmp","back0132.bmp","back0133.bmp","back0134.bmp","back0135.bmp","back0136.bmp","back0137.bmp","back0138.bmp","back0139.bmp",
                    "back0140.bmp","back0141.bmp","back0142.bmp","back0143.bmp","back0144.bmp","back0145.bmp","back0146.bmp","back0147.bmp","back0148.bmp","back0149.bmp",
                    "back0150.bmp","back0151.bmp","back0152.bmp","back0153.bmp","back0154.bmp","back0155.bmp","back0156.bmp","back0157.bmp","back0158.bmp","back0159.bmp",
                    "back0160.bmp","back0161.bmp","back0162.bmp","back0163.bmp","back0164.bmp","back0165.bmp","back0166.bmp","back0167.bmp","back0168.bmp","back0169.bmp",
                    "back0170.bmp","back0171.bmp","back0172.bmp","back0173.bmp","back0174.bmp","back0175.bmp","back0176.bmp","back0177.bmp","back0178.bmp","back0179.bmp",
                    "back0180.bmp","back0181.bmp","back0182.bmp","back0183.bmp","back0184.bmp","back0185.bmp","back0186.bmp","back0187.bmp","back0188.bmp","back0189.bmp",
                    "back0190.bmp","back0191.bmp","back0192.bmp","back0193.bmp","back0194.bmp","back0195.bmp","back0196.bmp","back0197.bmp","back0198.bmp","back0199.bmp",
                    "back0200.bmp","back0201.bmp","back0202.bmp","back0203.bmp","back0204.bmp","back0205.bmp","back0206.bmp","back0207.bmp","back0208.bmp","back0209.bmp",
                    "back0210.bmp","back0211.bmp","back0212.bmp","back0213.bmp","back0214.bmp","back0215.bmp","back0216.bmp","back0217.bmp","back0218.bmp","back0219.bmp",
                    "back0220.bmp","back0221.bmp","back0222.bmp","back0223.bmp","back0224.bmp","back0225.bmp","back0226.bmp","back0227.bmp","back0228.bmp","back0229.bmp",
                    "back0230.bmp","back0231.bmp","back0232.bmp","back0233.bmp","back0234.bmp","back0235.bmp","back0236.bmp","back0237.bmp","back0238.bmp","back0239.bmp",
                    "back0240.bmp","back0241.bmp","back0242.bmp","back0243.bmp","back0244.bmp","back0245.bmp","back0246.bmp","back0247.bmp","back0248.bmp","back0249.bmp",
                    "back0250.bmp","back0251.bmp","back0252.bmp","back0253.bmp","back0254.bmp","back0255.bmp","back0256.bmp","back0257.bmp","back0258.bmp","back0259.bmp",
                    "back0260.bmp","back0261.bmp","back0262.bmp","back0263.bmp","back0264.bmp","back0265.bmp","back0266.bmp","back0267.bmp","back0268.bmp","back0269.bmp",
                    "back0270.bmp","back0271.bmp","back0272.bmp","back0273.bmp","back0274.bmp","back0275.bmp","back0276.bmp","back0277.bmp","back0278.bmp","back0279.bmp",
                    "back0280.bmp","back0281.bmp","back0282.bmp","back0283.bmp","back0284.bmp","back0285.bmp","back0286.bmp","back0287.bmp","back0288.bmp","back0289.bmp",
                    "back0290.bmp","back0291.bmp","back0292.bmp","back0293.bmp","back0294.bmp","back0295.bmp","back0296.bmp","back0297.bmp","back0298.bmp","back0299.bmp",
                    "back0300.bmp","back0301.bmp","back0302.bmp","back0303.bmp","back0304.bmp","back0305.bmp","back0306.bmp","back0307.bmp","back0308.bmp","back0309.bmp",
                    "back0310.bmp","back0311.bmp","back0312.bmp","back0313.bmp","back0314.bmp","back0315.bmp","back0316.bmp","back0317.bmp","back0318.bmp","back0319.bmp",
                    "back0320.bmp","back0321.bmp","back0322.bmp","back0323.bmp","back0324.bmp","back0235.bmp","back0326.bmp","back0327.bmp","back0328.bmp","back0329.bmp",
                    "back0330.bmp","back0331.bmp","back0332.bmp","back0333.bmp","back0334.bmp","back0335.bmp","back0336.bmp","back0337.bmp","back0338.bmp","back0339.bmp",
                    "back0340.bmp","back0341.bmp","back0342.bmp","back0343.bmp","back0344.bmp","back0345.bmp","back0346.bmp","back0347.bmp","back0348.bmp","back0349.bmp",
                    "back0350.bmp","back0351.bmp","back0352.bmp","back0353.bmp","back0354.bmp","back0355.bmp","back0356.bmp","back0357.bmp","back0358.bmp","back0359.bmp",
                    "back0360.bmp","back0361.bmp","back0362.bmp","back0363.bmp","back0364.bmp","back0365.bmp","back0366.bmp","back0367.bmp","back0368.bmp","back0369.bmp",
                    "back0370.bmp","back0371.bmp","back0372.bmp","back0373.bmp","back0374.bmp","back0375.bmp","back0376.bmp","back0377.bmp","back0378.bmp","back0379.bmp",
                    "back0380.bmp","back0381.bmp","back0382.bmp","back0383.bmp","back0384.bmp","back0385.bmp","back0386.bmp","back0387.bmp","back0388.bmp","back0389.bmp",
                    "back0390.bmp","back0391.bmp","back0392.bmp","back0393.bmp","back0394.bmp","back0395.bmp","back0396.bmp","back0397.bmp","back0398.bmp","back0399.bmp",
                    "back0400.bmp","back0401.bmp","back0402.bmp","back0403.bmp","back0404.bmp","back0405.bmp","back0406.bmp","back0407.bmp","back0408.bmp","back0409.bmp",
                    "back0410.bmp","back0411.bmp","back0412.bmp","back0413.bmp","back0414.bmp","back0415.bmp","back0416.bmp","back0417.bmp","back0418.bmp","back0419.bmp",
                    "back0420.bmp","back0421.bmp","back0422.bmp","back0423.bmp","back0424.bmp","back0425.bmp","back0426.bmp","back0427.bmp","back0428.bmp","back0429.bmp",
                    "back0430.bmp","back0431.bmp","back0432.bmp","back0433.bmp","back0434.bmp","back0435.bmp","back0436.bmp","back0437.bmp","back0438.bmp","back0439.bmp",
                    "back0440.bmp","back0441.bmp","back0442.bmp","back0443.bmp","back0444.bmp","back0445.bmp","back0446.bmp","back0447.bmp","back0448.bmp","back0449.bmp",
                    "back0450.bmp","back0451.bmp","back0452.bmp","back0453.bmp","back0454.bmp","back0455.bmp","back0456.bmp","back0457.bmp","back0458.bmp","back0459.bmp",
                    "back0460.bmp","back0461.bmp","back0462.bmp","back0463.bmp","back0464.bmp","back0465.bmp","back0466.bmp","back0467.bmp","back0468.bmp","back0469.bmp",
                    "back0470.bmp","back0471.bmp","back0472.bmp","back0473.bmp","back0474.bmp","back0475.bmp","back0476.bmp","back0477.bmp","back0478.bmp","back0479.bmp",
                    "back0480.bmp","back0481.bmp","back0482.bmp","back0483.bmp","back0484.bmp","back0485.bmp","back0486.bmp","back0487.bmp","back0488.bmp","back0489.bmp",
                    "back0490.bmp","back0491.bmp","back0492.bmp","back0493.bmp","back0494.bmp","back0495.bmp","back0496.bmp","back0497.bmp","back0498.bmp","back0499.bmp",
                    "back0500.bmp","back0501.bmp","back0502.bmp","back0503.bmp","back0504.bmp","back0505.bmp","back0506.bmp","back0507.bmp","back0508.bmp","back0509.bmp",
                    "back0510.bmp","back0511.bmp","back0512.bmp","back0513.bmp","back0514.bmp","back0515.bmp","back0516.bmp","back0517.bmp","back0518.bmp","back0519.bmp",
                    "back0520.bmp","back0521.bmp","back0522.bmp","back0523.bmp","back0524.bmp","back0525.bmp","back0526.bmp","back0527.bmp","back0528.bmp","back0529.bmp",
                    "back0530.bmp","back0531.bmp","back0532.bmp","back0533.bmp","back0534.bmp","back0535.bmp","back0536.bmp","back0537.bmp","back0538.bmp","back0539.bmp",
                    "back0540.bmp","back0541.bmp","back0542.bmp","back0543.bmp","back0544.bmp","back0545.bmp","back0546.bmp","back0547.bmp","back0548.bmp","back0549.bmp",
                    "back0550.bmp","back0551.bmp","back0552.bmp","back0553.bmp","back0554.bmp","back0555.bmp","back0556.bmp","back0557.bmp","back0558.bmp","back0559.bmp",
                    "back0560.bmp","back0561.bmp","back0562.bmp","back0563.bmp","back0564.bmp","back0565.bmp","back0566.bmp","back0567.bmp","back0568.bmp","back0569.bmp",
                    "back0570.bmp","back0571.bmp","back0572.bmp","back0573.bmp","back0574.bmp","back0575.bmp","back0576.bmp","back0577.bmp","back0578.bmp","back0579.bmp",
                    "back0580.bmp","back0581.bmp","back0582.bmp","back0583.bmp","back0584.bmp","back0585.bmp","back0586.bmp","back0587.bmp","back0588.bmp","back0589.bmp",
                    "back0590.bmp","back0591.bmp","back0592.bmp","back0593.bmp","back0594.bmp","back0595.bmp","back0596.bmp","back0597.bmp","back0598.bmp","back0599.bmp",
                    "back0600.bmp","back0601.bmp","back0602.bmp","back0603.bmp","back0604.bmp","back0605.bmp","back0606.bmp","back0607.bmp","back0608.bmp","back0609.bmp",
                    "back0610.bmp","back0611.bmp","back0612.bmp","back0613.bmp","back0614.bmp","back0615.bmp","back0616.bmp","back0617.bmp","back0618.bmp","back0619.bmp",
                    "back0620.bmp","back0621.bmp","back0622.bmp","back0623.bmp","back0624.bmp","back0625.bmp","back0626.bmp","back0627.bmp","back0628.bmp","back0629.bmp",
                    "back0630.bmp","back0631.bmp","back0632.bmp","back0633.bmp","back0634.bmp","back0635.bmp","back0636.bmp","back0637.bmp","back0638.bmp","back0639.bmp",
                    "back0640.bmp","back0641.bmp","back0642.bmp","back0643.bmp","back0644.bmp","back0645.bmp","back0646.bmp","back0647.bmp","back0648.bmp","back0649.bmp",
                    "back0650.bmp","back0651.bmp","back0652.bmp","back0653.bmp","back0654.bmp","back0655.bmp","back0656.bmp","back0657.bmp","back0658.bmp","back0659.bmp",
                    "back0660.bmp","back0661.bmp","back0662.bmp","back0663.bmp","back0664.bmp","back0665.bmp","back0666.bmp","back0667.bmp","back0668.bmp","back0669.bmp",
                    "back0670.bmp","back0671.bmp","back0672.bmp","back0673.bmp","back0674.bmp","back0675.bmp","back0676.bmp","back0677.bmp","back0678.bmp","back0679.bmp",
                    "back0680.bmp","back0681.bmp","back0682.bmp","back0683.bmp","back0684.bmp","back0685.bmp","back0686.bmp","back0687.bmp","back0688.bmp","back0689.bmp",
                    "back0690.bmp","back0691.bmp","back0692.bmp","back0693.bmp","back0694.bmp","back0695.bmp","back0696.bmp","back0697.bmp","back0698.bmp","back0699.bmp",
                    "back0700.bmp","back0701.bmp","back0702.bmp","back0703.bmp","back0704.bmp","back0705.bmp","back0706.bmp","back0707.bmp","back0708.bmp","back0709.bmp",
                    "back0710.bmp","back0711.bmp","back0712.bmp","back0713.bmp","back0714.bmp","back0715.bmp","back0716.bmp","back0717.bmp","back0718.bmp","back0719.bmp",
                    "back0720.bmp","back0721.bmp","back0722.bmp","back0723.bmp","back0724.bmp","back0725.bmp","back0726.bmp","back0727.bmp","back0728.bmp","back0729.bmp",
                    "back0730.bmp","back0731.bmp","back0732.bmp","back0733.bmp","back0734.bmp","back0735.bmp","back0736.bmp","back0737.bmp","back0738.bmp","back0739.bmp",
                    "back0740.bmp","back0741.bmp","back0742.bmp","back0743.bmp","back0744.bmp","back0745.bmp","back0746.bmp","back0747.bmp","back0748.bmp","back0749.bmp",
                    "back0750.bmp","back0751.bmp","back0752.bmp","back0753.bmp","back0754.bmp","back0755.bmp","back0756.bmp","back0757.bmp","back0758.bmp","back0759.bmp",
                    "back0760.bmp","back0761.bmp","back0762.bmp","back0763.bmp","back0764.bmp","back0765.bmp","back0766.bmp","back0767.bmp","back0768.bmp","back0769.bmp",
                    "back0770.bmp","back0771.bmp","back0772.bmp","back0773.bmp","back0774.bmp","back0775.bmp","back0776.bmp","back0777.bmp","back0778.bmp","back0779.bmp",
                    "back0780.bmp","back0781.bmp","back0782.bmp","back0783.bmp","back0784.bmp","back0785.bmp","back0786.bmp","back0787.bmp","back0788.bmp","back0789.bmp",
                    "back0790.bmp","back0791.bmp","back0792.bmp","back0793.bmp","back0794.bmp","back0795.bmp","back0796.bmp","back0797.bmp","back0798.bmp","back0799.bmp",
                    "back0800.bmp","back0801.bmp","back0802.bmp","back0803.bmp","back0804.bmp","back0805.bmp","back0806.bmp","back0807.bmp","back0808.bmp","back0809.bmp",
                    "back0810.bmp","back0811.bmp","back0812.bmp","back0813.bmp","back0814.bmp","back0815.bmp","back0816.bmp","back0817.bmp","back0818.bmp","back0819.bmp",
                    "back0820.bmp","back0821.bmp","back0822.bmp","back0823.bmp","back0824.bmp","back0825.bmp","back0826.bmp","back0827.bmp","back0828.bmp","back0829.bmp",
                    "back0830.bmp","back0831.bmp","back0832.bmp","back0833.bmp","back0834.bmp","back0835.bmp","back0836.bmp","back0837.bmp","back0838.bmp","back0839.bmp",
                    "back0840.bmp","back0841.bmp","back0842.bmp","back0843.bmp","back0844.bmp","back0845.bmp","back0846.bmp","back0847.bmp","back0848.bmp","back0849.bmp",
                    "back0850.bmp","back0851.bmp","back0852.bmp","back0853.bmp","back0854.bmp","back0855.bmp","back0856.bmp","back0857.bmp","back0858.bmp","back0859.bmp",
                    "back0860.bmp","back0861.bmp","back0862.bmp","back0863.bmp","back0864.bmp","back0865.bmp","back0866.bmp","back0867.bmp","back0868.bmp","back0869.bmp",
                    "back0870.bmp","back0871.bmp","back0872.bmp","back0873.bmp","back0874.bmp","back0875.bmp","back0876.bmp","back0877.bmp","back0878.bmp","back0879.bmp",
                    "back0880.bmp","back0881.bmp","back0882.bmp","back0883.bmp","back0884.bmp","back0885.bmp","back0886.bmp","back0887.bmp","back0888.bmp","back0889.bmp",
                    "back0890.bmp","back0891.bmp","back0892.bmp","back0893.bmp","back0894.bmp","back0895.bmp","back0896.bmp","back0897.bmp","back0898.bmp","back0899.bmp",
                    "back0900.bmp","back0901.bmp","back0902.bmp","back0903.bmp","back0904.bmp","back0905.bmp","back0906.bmp","back0907.bmp","back0908.bmp","back0909.bmp",
                    "back0910.bmp","back0911.bmp","back0912.bmp","back0913.bmp","back0914.bmp","back0915.bmp","back0916.bmp","back0917.bmp","back0918.bmp","back0919.bmp",
                    "back0920.bmp","back0921.bmp","back0922.bmp","back0923.bmp","back0924.bmp","back0925.bmp","back0926.bmp","back0927.bmp","back0928.bmp","back0929.bmp",
                    "back0930.bmp","back0931.bmp","back0932.bmp","back0933.bmp","back0934.bmp","back0935.bmp","back0936.bmp","back0937.bmp","back0938.bmp","back0939.bmp",
                    "back0940.bmp","back0941.bmp","back0942.bmp","back0943.bmp","back0944.bmp","back0945.bmp","back0946.bmp","back0947.bmp","back0948.bmp","back0949.bmp",
                    "back0950.bmp","back0951.bmp","back0952.bmp","back0953.bmp","back0954.bmp","back0955.bmp","back0956.bmp","back0957.bmp","back0958.bmp","back0959.bmp",
                    "back0960.bmp","back0961.bmp","back0962.bmp","back0963.bmp","back0964.bmp","back0965.bmp","back0966.bmp","back0967.bmp","back0968.bmp","back0969.bmp",
                    "back0970.bmp","back0971.bmp","back0972.bmp","back0973.bmp","back0974.bmp","back0975.bmp","back0976.bmp","back0977.bmp","back0978.bmp","back0979.bmp",
                    "back0980.bmp","back0981.bmp","back0982.bmp","back0983.bmp","back0984.bmp","back0985.bmp","back0986.bmp","back0987.bmp","back0988.bmp","back0989.bmp",
                    "back0990.bmp","back0991.bmp","back0992.bmp","back0993.bmp","back0994.bmp","back0995.bmp","back0996.bmp","back0997.bmp","back0998.bmp","back0999.bmp",
                    "back1000.bmp","back1001.bmp","back1002.bmp","back1003.bmp","back1004.bmp","back1005.bmp","back1006.bmp","back1007.bmp","back1008.bmp","back1009.bmp",
                    "back1010.bmp","back1011.bmp","back1012.bmp","back1013.bmp","back1014.bmp","back1015.bmp","back1016.bmp","back1017.bmp","back1018.bmp","back1019.bmp",
                    "back1020.bmp","back1021.bmp","back1022.bmp","back1023.bmp","back1024.bmp","back1025.bmp","back1026.bmp","back1027.bmp","back1028.bmp","back1029.bmp",
                    "back1030.bmp","back1031.bmp","back1032.bmp","back1033.bmp","back1034.bmp","back1035.bmp","back1036.bmp","back1037.bmp","back1038.bmp","back1039.bmp",
                    "back1040.bmp","back1041.bmp","back1042.bmp","back1043.bmp","back1044.bmp","back1045.bmp","back1046.bmp","back1047.bmp","back1048.bmp","back1049.bmp",
                    "back1050.bmp","back1051.bmp","back1052.bmp","back1053.bmp","back1054.bmp","back1055.bmp","back1056.bmp","back1057.bmp","back1058.bmp","back1059.bmp",
                    "back1060.bmp","back1061.bmp","back1062.bmp","back1063.bmp","back1064.bmp","back1065.bmp","back1066.bmp","back1067.bmp","back1068.bmp","back1069.bmp",
                    "back1070.bmp","back1071.bmp","back1072.bmp","back1073.bmp","back1074.bmp","back1075.bmp","back1076.bmp","back1077.bmp","back1078.bmp","back1079.bmp",
                    "back1080.bmp","back1081.bmp","back1082.bmp","back1083.bmp","back1084.bmp","back1085.bmp","back1086.bmp","back1087.bmp","back1088.bmp","back1089.bmp",
                    "back1090.bmp","back1091.bmp","back1092.bmp","back1093.bmp","back1094.bmp","back1095.bmp","back1096.bmp","back1097.bmp","back1098.bmp","back1099.bmp",
                    "back1100.bmp","back1101.bmp","back1102.bmp","back1103.bmp","back1104.bmp","back1105.bmp","back1106.bmp","back1107.bmp","back1108.bmp","back1109.bmp",
                    "back1110.bmp","back1111.bmp","back1112.bmp","back1113.bmp","back1114.bmp","back1115.bmp","back1116.bmp","back1117.bmp","back1118.bmp","back1119.bmp",
                    "back1120.bmp","back1121.bmp","back1122.bmp","back1123.bmp","back1124.bmp","back1125.bmp","back1126.bmp","back1127.bmp","back1128.bmp","back1129.bmp",
                    "back1130.bmp","back1131.bmp","back1132.bmp","back1133.bmp","back1134.bmp","back1135.bmp","back1136.bmp","back1137.bmp","back1138.bmp","back1139.bmp",
                    "back1140.bmp","back1141.bmp","back1142.bmp","back1143.bmp","back1144.bmp","back1145.bmp","back1146.bmp","back1147.bmp","back1148.bmp","back1149.bmp",
                    "back1150.bmp","back1151.bmp","back1152.bmp","back1153.bmp","back1154.bmp","back1155.bmp","back1156.bmp","back1157.bmp","back1158.bmp","back1159.bmp",
                    "back1160.bmp","back1161.bmp","back1162.bmp","back1163.bmp","back1164.bmp","back1165.bmp","back1166.bmp","back1167.bmp","back1168.bmp","back1169.bmp",
                    "back1170.bmp","back1171.bmp","back1172.bmp","back1173.bmp","back1174.bmp","back1175.bmp","back1176.bmp","back1177.bmp","back1178.bmp","back1179.bmp",
                    "back1180.bmp","back1181.bmp","back1182.bmp","back1183.bmp","back1184.bmp","back1185.bmp","back1186.bmp","back1187.bmp","back1188.bmp","back1189.bmp",
                    "back1190.bmp","back1191.bmp","back1192.bmp","back1193.bmp","back1194.bmp","back1195.bmp","back1196.bmp","back1197.bmp","back1198.bmp","back1199.bmp",
                    "back1200.bmp","back1201.bmp","back1202.bmp","back1203.bmp","back1204.bmp","back1205.bmp","back1206.bmp","back1207.bmp","back1208.bmp","back1209.bmp",
                    "back1210.bmp","back1211.bmp","back1212.bmp","back1213.bmp","back1214.bmp","back1215.bmp","back1216.bmp","back1217.bmp","back1218.bmp","back1219.bmp",
                    "back1220.bmp","back1221.bmp","back1222.bmp","back1223.bmp","back1224.bmp"
                };
//for collision of the bird
//i want to build that in such a way that if the bird collide then the col variable will increase then such things happen
int col;
float x=xball,y=yball;
//start update
int startx,startdot;
//for birds
int bird=1, birdstate;
int consol,consolout,consol2out;
// dark mode sound on off music on off
int dark,sound,music;
// debugging variable
int hudai=0;
//for pigs/gems
int gem1,gem2,gem3,gem4,gem5,gem6,gem7,gem8,gem9;
//for number of turns
int num;
int backgnd;
int level;
void startdotupdate()
{
    if (consol==0)
    {
        startdot++;
        startdot=startdot%4;
    }
}
void startupdate()
{
    if(check == 0 || check ==2)
    {
        iPauseTimer(1);
    }
    if(consol==0)
    {
        startx+=4;
        iPauseTimer(4);
        if(startx==1000)
        {
            iPauseTimer(2);
            iPauseTimer(3);
            iResumeTimer(4);
            consol++;
        }
    }

}

// this func will tell us which bird will tell us what not implemented until now
void birds()
{
    if (bird == 0)
    {

    }
    if (bird == 1)
    {
        if (birdstate%2== 1)
        {
            v=v*3;
        }
    }
    if (bird == 2)
    {

    }
    if (bird ==3)
    {

    }
}
void mapp()
{
    if (direction==1)
    {
        mapping++;
        if(mapping==100)
        {
            direction=0;
        }
    }
    else if(direction==0)
    {
        mapping--;
        if(mapping==0)
        {
            direction=1;
        }
    }
    //v=mapping;
}
void projectile()//projectile with collision also has gems
{
    if(check ==2)
    {
        if(yball>=0)
        {
            //int dx=-1;
            t=t+0.1;
            if(xball>=500 && xball<=510)
            {
                if (yball>=200 &&yball<=240  && col!=1)
                {
                    if(level==0){
                    col=1;
                    x=xball;
                    y=yball;
                    tcol=t;
                    vx=-vx/5;
                    vy=vy-g*tcol;
                }
                }
            }
            else if(xball>=400 && xball<=440)
            {
                if (yball>=300 &&yball<=380  && col!=1)
                {
                    if(level==1||level==2){
                    col=1;
                    x=xball;
                    y=yball;
                    tcol=t;
                    vx=-vx/5;
                    vy=vy-g*tcol;
                }
                }
            }
            else if(xball>=500 && xball<=540)
            {
                if (yball>=200 &&yball<=240  && col!=1)
                {
                    if(level==1||level==2){
                    col=1;
                    x=xball;
                    y=yball;
                    tcol=t;
                    vx=-vx/5;
                    vy=vy-g*tcol;
                }
                }
            }
            else if(xball>=300 && xball<=340)
            {
                if (yball>=200 &&yball<=280  && col!=1)
                {
                    if(level==2){
                    col=1;
                    x=xball;
                    y=yball;
                    tcol=t;
                    vx=-vx/5;
                    vy=vy-g*tcol;
                }
                }
            }
            else if(xball >=600 && xball<=610)
            {
                if(yball>=150 && yball<= 200 && col != 2)
                {
                    if(level==0||level==1||level==2){
                    col=2;
                    x=xball;
                    y=yball;
                    tcol=t;
                    vx=vx/4;
                    vy=vy-g*t;
                }
                }
            }
            else if (xball>=510 && xball <=550 && col != 3)
            {
                if (yball >=240 && yball <=255)
                {
                    if(level==0){
                    col=3;
                    x=xball;
                    y=yball;
                    tcol=t;
                    vx=vx/2;
                    vy=-(vy-g*tcol)/2;
                }
                }
            }
            else if (xball>=495 && xball <= 510)
            {
                if (yball >=240 && yball <=255 && col !=4)
                {
                    if(level==0){
                    col=4;
                    x=xball;
                    y=yball;
                    tcol=t;
                    vx=-vx/5;
                    vy=-((vy-g*t)/5);
                }
                }
            }
            if(col==1)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);
//                if(xball<=500 || xball>=510 || yball<=200 || yball>=240)
//                {
//                    col=0;
////                    vxi=vx;
////                    vyi=vy;
//                }

            }
            else if(col==2)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);
//                if(xball <=600 || xball>=610 || yball<=150 || yball>= 200)
//                {
//                    col=0;
////                    vxi=vx;
////                    vyi=vy;
//                }
            }
            else if (col ==3)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);

//                if (xball<=510 || xball >=550 || yball <=240 || yball >=255)
//                {
//                    col=0;
////                    vxi=vx;
////                    vyi=vy;
//                }
            }
            else if (col== 4)
            {
                xball=x+vx*(t-tcol);
                yball=y+vy*(t-tcol)-0.5*g*(t-tcol)*(t-tcol);
//                if(xball<=495 || xball >= 510 || yball <=240 || yball >=255)
//                {
//                    col=0;
////                    vxi=vx;
////                    vyi=vy;
//                }
            }
            else
            {
                xball=vxi*t+75;
                yball=vyi*t-0.5*g*t*t+75;
            }
            if(level==0){
            if(xball >=822 && xball<=900)
            {
                if(yball>=115&& yball<=190)
                {
                    gem1=1;
                }

                if (gem1!=1)
                    gem1=0;
            }

            else if(xball >=715 && xball<=786)
            {
                if(yball>=0 && yball<=75)
                {
                    gem2=1;
                }
                if (gem2!=1)
                    gem2=0;
            }
            else if(xball >=885 && xball<=945)
            {
                if(yball>=30 && yball<=90 )
                {
                    gem3=1;
                }
                if (gem3!=1)
                    gem3=0;
            }
            else if(xball >=655 && xball<=705)
            {
                if(yball>=115&& yball<=162)
                {
                    gem4=1;
                }
                if (gem4!=1)
                    gem4=0;
            }
            else if(xball >=660 && xball<=797)
            {
                if(yball>=105 && yball<=123)
                {
                    gem7=1;
                }
                if (gem7!=1)
                    gem7=0;
            }
            }
            if(level==1)
            {
                if(xball >=744 && xball<=816)
                {
                    if(yball>=318& yball<=406)
                    {
                        gem1=1;
                    }

                    if (gem1!=1)
                        gem1=0;
                }

                else if(xball >=815 && xball<=886)
                {
                    if(yball>=105 && yball<=185 )
                    {
                        gem2=1;
                    }
                    if (gem2!=1)
                        gem2=0;
                }
                else if(xball >=739 && xball<=800)
                {
                    if(yball>=20 && yball<=84 )
                    {
                        gem3=1;
                    }
                    if (gem3!=1)
                        gem3=0;
                }
                else if(xball >=615 && xball<=665)
                {
                    if(yball>=98&& yball<=148)
                    {
                        gem4=1;
                    }
                    if (gem4!=1)
                        gem4=0;
                }
                else if(xball >=874 && xball<=904)
                {
                    if(yball>=38 && yball<=65)
                    {
                        {
                            gem5=1;
                        }
                    }
                    if (gem5!=1)
                        gem5=0;
                }
            }
            if(level==2)
            {
                if(xball >=660 && xball<=737)
                {
                    if(yball>=218 && yball<=306 )
                    {
                        gem1=1;
                    }

                    if (gem1!=1)
                        gem1=0;
                }

                else if(xball >=730 && xball<=801 )
                {
                    if(yball>=300 && yball<=380)
                    {
                        gem2=1;
                    }
                    if (gem2!=1)
                        gem2=0;
                }
                else if(xball >=427 && xball<=487 )
                {
                    if(yball>=105 && yball<=169 )
                    {
                        gem3=1;
                    }
                    if (gem3!=1)
                        gem3=0;
                }
                else if(xball >=627 && xball<=677)
                {
                    if(yball>=105 && yball<=157 )
                    {
                        gem4=1;
                    }
                    if (gem4!=1)
                        gem4=0;
                }
                else if(xball >=757 && xball<=790)
                {
                    if(yball>=218 && yball<=250)
                    {

                        {
                            gem5=1;
                        }
                    }
                    if (gem5!=1)
                        gem5=0;
                }
                else if(xball >=827 && xball<=860)
                {
                    if(yball>=105 && yball<=138)
                    {

                        {
                            gem6=1;
                        }
                    }
                    if (gem6!=1)
                        gem6=0;
                }
            }



        }
        else
        {
            t=0;
            check=0;
            mapping=col=0;
            direction=1;
            xball=yball=75;
            x=xball;
            y=yball;
            num++;
        }
        //the console 3 can be only operated by the console 2 as an input this if is done when game is over
        if(num==5 && gem1==0 && gem2==0 && gem3==0 && gem4==0 && gem5==0 && gem6==0)
        {
            consol=3;
            consol2out=1;
            num=0;
            gem1=0;
            gem2=0;
            gem3=0;
            gem4=0;
            gem5=0;
            gem6=0;
        }
        if(num==5 && gem1==1||num==5 && gem2==1|| num==5 && gem3==1||num==5 && gem4==1||num==5 && gem5==1||num==5 && gem6==1)
        {
            level++;
            num=0;
            gem1=0;
            gem2=0;
            gem3=0;
            gem4=0;
            gem5=0;
            gem6=0;
            consol=3;
            consol2out=2;
            if (level==3)
            {
                level=0;
                consol=3;
                consol2out=3;
            }
        }
    }

}

void backgrounddraw()
{
    backgnd++;
    if(backgnd==1225)
        backgnd=backgnd%1225;
    iShowBMP(0,0,arr[backgnd]);
}
//void backgroundupdate()
//{
//    backgnd++;
//
//}
void iDraw()
{
    //place your drawing codes here
    iClear();
    if(consol==0)
    {

        iShowBMP(0,0,"angry bird start.bmp");
        iShowBMP2(350,50,"ibirds logo.bmp",0);
        iText(450,30,"Loading",GLUT_BITMAP_TIMES_ROMAN_24);
        if(startdot==0)
        {
            iFilledRectangle(533,24,4,4);
        }
        if(startdot==1)
        {
            iFilledRectangle(533,24,4,4);
            iFilledRectangle(539,24,4,4);
        }
        if(startdot==2)
        {
            iFilledRectangle(533,24,4,4);
            iFilledRectangle(539,24,4,4);
            iFilledRectangle(545,24,4,4);
        }
        if(startdot==3)
        {
            iFilledRectangle(533,24,4,4);
            iFilledRectangle(539,24,4,4);
            iFilledRectangle(545,24,4,4);
            iFilledRectangle(551,24,4,4);
        }
        /*
        int m=533;
        for(int i=0;i<startdot;i++)
        {
            iFilledRectangle(3,24,4,4);
            m+=6;
        }*/
        iFilledRectangle(0,15,startx,5);
    }

    if(consol == 1)
    {
        if(dark ==0)
        {
            backgrounddraw();
        }
        else if (dark ==1)
        {
            iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
        }
        //csy=22;
        iSetColor(255,255,0);
        iEllipse(500,20+20,100,20);
        iEllipse(500,60+20,100,20);
        iEllipse(500,100+20,106,22);
        iEllipse(500,140+20,100,20);
        iEllipse(500,180+20,100,20);
        iEllipse(500,220+20,100,20);
        iEllipse(500,260+20,100,20);
        /*
        iRectangle(400,20,200,35);
        iRectangle(400,60,200,35);
        iRectangle(400,100,200,35);
        iRectangle(400,140,200,35);
        iRectangle(400,180,200,35);
        iRectangle(400,220,200,35);
        iRectangle(400,260,200,35);
        */
        iSetColor(255,255,255);
        //iFilledRectangle(401,csy,197,32);
        //iSetColor(0,0,255);
        iText(475,31,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(461,71,"ABOUT",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(408,111,"HALL OF FAMES",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(445,151,"SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(465,191,"HELPS",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(440,231,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(440,271,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    if (consol==2)
    {
        //user presses continue
        if (consolout==1)
        {
            iText(400,400,"this section is still developing",GLUT_BITMAP_TIMES_ROMAN_24);
            iCircle(55,450,35,1000);
            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        }
        //uesr presses new game
        if(consolout==2)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iShowBMP2(55,20,"shooter.bmp",0);

            iShowBMP2(24,442,"back.bmp",0);
            iSetColor(255,0,0);
            //for power indicator
            iRectangle(10,20,8,101);
            iFilledRectangle(11,21,6,mapping);
            //
            //axis drawing
            iLine(0,1,800,1);
            iLine(1,0,1,650);
            //
            //iSetColor(255,255,255);
            //iCircle(75,75,80,1000);
            iSetColor(0,0,0);
            //showing line

            //iFilledCircle(xshow+75,yshow+75,5,100);
            // iFilledCircle(xshow+35,yshow+75,5,100);
            iLine(75,95,xshow+75,yshow+95);
            iSetColor(255,0,0);
            //non removable obstacle
            iSetColor(125,125,125);
            iFilledRectangle(500,240,10,10);
            //iFilledRectangle(500,200,50,50);
            if(col!= 2)
            {
                iSetColor(0,255,0);
                //removable obstacle
                iShowBMP2(600,150,"wood4.bmp",0);

            }
            iShowBMP2(800,392,"scoreboard.bmp",0);
            //iLine(100,240,800,240);
            iSetColor(0,0,255);
            iShowBMP2(xball-35,yball,"bird1.bmp",0);
            if(level==0)
            {
                iShowBMP2(500,200,"wood4.bmp",0);
                iShowBMP2(510,240,"wood6.bmp",0);
                iShowBMP2(620,20,"wood1.bmp",0);
                if(gem7==0)
                iShowBMP2(660,105,"wood2.bmp",0);
                iShowBMP2(827,20,"wood2.bmp",0);
                iShowBMP2(827,35,"wood1.bmp",0);
                //   iShowBMP2(827,90,"wood3.bmp",0);
                if(gem1==0)
                {
                    //iFilledRectangle(800,20,24,24);
                    iShowBMP2(817,115,"pig1.bmp",0);
                }
                if(gem2==0)
                {
                    iShowBMP2(720,0,"pig2.bmp",0);
                    //iShowBMP2(700,20,"icon_3.bmp",0);
                }
                if(gem3==0)
                {
                    iShowBMP2(890,30,"pig3.bmp",0);
                    //iShowBMP2(900,20,"icon_2.bmp",0);
                }
                if(gem4==0)
                {
                    iShowBMP2(660,115,"pig4.bmp",0);
                    //iShowBMP2(850,20,"icon_3.bmp",0);
                }
                /*
                if(gem5==0)
                {
                    iFilledRectangle(750,20,24,24);
                    //iShowBMP2(750,20,"icon_2.bmp",0);
                }
                if(gem6==0)
                {
                    iFilledRectangle(825,20,24,24);
                    //iShowBMP2(825,20,"icon_3.bmp",0);
                }
                */
            }
            if(level==1)
            {
                iShowBMP2(500,200,"wood8.bmp",0);
                iShowBMP2(400,300,"wood8.bmp",0);
                iShowBMP2(620,20,"wood1.bmp",0);
                iShowBMP2(660,20,"wood2.bmp",0);
                iShowBMP2(827,20,"wood2.bmp",0);
                iShowBMP2(827,35,"wood1.bmp",0);
                iShowBMP2(660,300,"wood2.bmp",0);
                if(gem1==0)
                {
                    iShowBMP2(744,318,"pig1.bmp",0);
                    //iShowBMP2(800,20,"icon_2.bmp",0);
                }
                if(gem2==0)
                {
                    iShowBMP2(820,105,"pig2.bmp",0);
                    //iShowBMP2(700,20,"icon_3.bmp",0);
                }
                if(gem3==0)
                {
                    iShowBMP2(744,20,"pig3.bmp",0);
                    //iShowBMP2(900,20,"icon_2.bmp",0);
                }
                if(gem4==0)
                {
                    iShowBMP2(620,98,"pig4.bmp",0);
                    //iShowBMP2(850,20,"icon_3.bmp",0);
                }
                if(gem5==0)
                {
                    iShowBMP2(874,38,"pig5.bmp",0);
                    //iShowBMP2(750,20,"icon_2.bmp",0);
                }/*
                if(gem6==0)
                {
                    iFilledRectangle(825,20,24,24);
                    //iShowBMP2(825,20,"icon_3.bmp",0);
                }*/
            }
            if(level==2)
            {
                iShowBMP2(300,200,"wood8.bmp",0);
                iShowBMP2(400,300,"wood8.bmp",0);
                iShowBMP2(500,200,"wood8.bmp",0);
                iShowBMP2(827,20,"wood1.bmp",0);
                iShowBMP2(627,20,"wood1.bmp",0);
                iShowBMP2(427,20,"wood1.bmp",0);
                iShowBMP2(660,200,"wood2.bmp",0);
                iShowBMP2(730,300,"wood2.bmp",0);
                iShowBMP2(890,0,"egg.bmp",0);
                if(gem1==0)
                {
                    iShowBMP2(660,218,"pig1.bmp",0);
                    //iShowBMP2(800,20,"icon_2.bmp",0);
                }
                if(gem2==0)
                {
                    iShowBMP2(730,300,"pig2.bmp",0);
                    //iShowBMP2(700,20,"icon_3.bmp",0);
                }
                if(gem3==0)
                {
                    iShowBMP2(427,105,"pig3.bmp",0);
                    //iShowBMP2(900,20,"icon_2.bmp",0);
                }
                if(gem4==0)
                {
                    iShowBMP2(627,105,"pig4.bmp",0);
                    //iShowBMP2(850,20,"icon_3.bmp",0);
                }
                if(gem5==0)
                {
                    iShowBMP2(827,105,"pig5.bmp",0);
                    //iShowBMP2(750,20,"icon_2.bmp",0);
                }
                if(gem6==0)
                {
                    iShowBMP2(757,218,"pig5.bmp",0);
                    //iShowBMP2(825,20,"icon_3.bmp",0);
                }
            }
        }
        //helps
        if (consolout==3)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
            }
            iCircle(55,450,35,1000);
            iText(24,442,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
            iShowBMP2(0,0,"help.bmp",0);
            iShowBMP2(24,442,"back.bmp",0);
        }
        //settings
        if (consolout==4)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
                iSetColor(255,255,255);
                iShowBMP2(450,20,"tick sign.bmp",255);
            }/*
            if(dark ==1)
            {
                iShowBMP2(450,20,"tick sign.bmp",0);
            }*/
            iRectangle(200,20,200,35);
            iRectangle(450,20,35,35);
            iText(200,31,"DARK MODE",GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(450,60,35,35);
            iRectangle(450,100,35,35);
            iRectangle(200,60,200,35);
            iRectangle(200,100,200,35);
            //iRectangle(500,100,200,35);
            iShowBMP2(24,442,"back.bmp",0);


        }
        //high score
        if (consolout==5)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
            }
            iSetColor(0,0,0);
            iRectangle(200,20,200,35);
            iRectangle(200,60,200,35);
            iRectangle(200,100,200,35);
            iRectangle(200,140,200,35);
            iRectangle(200,180,200,35);
            iRectangle(500,20,100,35);
            iRectangle(500,60,100,35);
            iRectangle(500,100,100,35);
            iRectangle(500,140,100,35);
            iRectangle(500,180,100,35);
            iShowBMP2(24,442,"back.bmp",0);

            iText(205,31,"scorename[0]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,71,"scorename[1]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,111,"scorename[2]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,151,"scorename[3]",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(205,191,"scorename[4]",GLUT_BITMAP_TIMES_ROMAN_24);

        }
        //about
        if (consolout==6)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"angry bird consol 1.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird consol 1 dark mode.bmp");
            }
            iSetColor(255,255,255);
            iShowBMP(0,0,"about.bmp");
            iShowBMP2(24,442,"back.bmp",0);

        }
        //presses exit
    }

    if(consol==3)
    {
        if(consol2out==0)//presses back
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,255);
            iRectangle(300,125,400,200);
            iText(430,275,"Are you sure?",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,255,0);
            iFilledRectangle(360,150,80,50);
            iSetColor(255,0,0);
            iFilledRectangle(540,150,80,50);
            iSetColor(255,255,0);
            iText(382,190-25,"NO",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(557,190-25,"YES",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(consol2out==1)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,255);
            iFilledEllipse(500,250,100,25,1000);
            iFilledEllipse(350,200-20,50,20,100);
            //iFilledEllipse(500,200,50,20,100);
            iFilledEllipse(650,200-20,50,20,100);
            iSetColor(255,255,255);
            iText(422,240,"GAME OVER!!",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(327,192-20,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(625,192-20,"Retry",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,0,0);
            iText(422,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(consol2out==2)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,255);
            iFilledEllipse(500,250,100,25,1000);
            iFilledEllipse(350,200-20,50,20,100);
            iFilledEllipse(500,200-20,50,20,100);
            iFilledEllipse(650,200-20,50,20,100);
            iSetColor(255,255,255);
            iText(420,240,"Congratulations!!",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(327,192-20,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(625-150,192-20,"Retry",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(613,192-20,"Forward",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,0,0);
            iText(422,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(consol2out==3)
        {
            if(dark ==0)
            {
                iShowBMP(0,0,"background.bmp");
            }
            else if (dark ==1)
            {
                iShowBMP(0,0,"angry bird dark mode background.bmp");
            }
            iSetColor(0,0,255);
            iFilledEllipse(500,250,100,25,1000);
            iFilledEllipse(350,200-20,50,20,100);
            //iFilledEllipse(500,200,50,20,100);
            iFilledEllipse(650,200-20,50,20,100);
            iSetColor(255,255,255);
            iText(420,240,"Congratulations!!",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(327,192-20,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(625,192-20,"Retry",GLUT_BITMAP_TIMES_ROMAN_24);
            //iText(613,192,"Forward",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,0,0);
            iText(422,100,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }

    if(consol==4)
    {
        if(dark ==0)
        {
            iShowBMP(0,0,"background.bmp");
        }
        else if (dark ==1)
        {
            iShowBMP(0,0,"angry bird dark mode background.bmp");
        }
        iSetColor(0,0,255);
        iRectangle(300,175,400,200);
        iText(350,325,"Do you want to save the game?",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,0);
        iFilledRectangle(360,200,80,50);
        iSetColor(255,0,0);
        iFilledRectangle(540,200,80,50);
        iSetColor(255,255,0);
        iText(382,190+25,"NO",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(557,190+25,"YES",GLUT_BITMAP_TIMES_ROMAN_24);
    }

}
void iMouseMove(int mx, int my)
{
//place your codes here
}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(consol == 1)
        {
            if(mx>=395 && mx<=605 && my>=260 && my<=295)
            {
                consol++;
                iPauseTimer(4);
                consolout=1;
            }

            if(mx>=395 && mx<=605 && my>=220 && my<=255)
            {
                consol++;
                iPauseTimer(4);
                consolout=2;
            }

            if(mx>=395 && mx<=605 && my>=180 && my<=215)
            {
                consol++;
                iPauseTimer(4);
                consolout=3;
            }

            if(mx>=395 && mx<=605 && my>=140 && my<=175)
            {
                consol++;
                iPauseTimer(4);
                consolout=4;
            }

            if(mx>=395 && mx<=605 && my>=100 && my<=135)
            {
                consol++;
                iPauseTimer(4);
                consolout=5;
            }

            if(mx>=395 && mx<=605 && my>=60 && my<=95)
            {
                consol++;
                iPauseTimer(4);
                consolout=6;
            }

            if(mx>=395 && mx<=605 && my>=20 && my<=55)
            {
                exit(0);
            }
        }
        if (consol == 2)
        {
            if (consolout==1)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    iResumeTimer(4);
                    consolout=0;
                }
            }
            if (consolout==2)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol++;
                    consol2out=0;
                }
            }
            if (consolout==3)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    iResumeTimer(4);
                    consolout=0;
                }
            }

            if (consolout==4)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    iResumeTimer(4);
                    consolout=0;
                }
                if(mx>450 && mx<485 && my>20 && my<55)
                {
                    if(dark== 0)
                    {
                        dark=1;
                    }
                    else if (dark == 1)
                    {
                        dark =0;
                    }
                }
            }

            if (consolout==5)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    iResumeTimer(4);
                    consolout=0;
                }
            }

            if (consolout==6)
            {
                if(mx>=55-35 && mx<=55+35 && my>=450-35 && my<=450+35)
                {
                    consol--;
                    iResumeTimer(4);
                    consolout=0;
                }
            }
        }

        if(consol==3)
        {
            if(consol2out==0)//are you sure????
            {
                if(mx>=360 && mx<=360+80 && my>=150 && my<=200)
                {
                    consol=2;
                    consolout=2;
                }
                if(mx>=540 && mx<=540+80 && my>=150 && my<=200)
                {
                    consol=4;
                }
            }
            if(consol2out==1)//game over
            {
                if(mx>=300 && mx<=400 && my >=160 && my<=200)
                {
                    consol++;
                    consol2out=0;
                }
                if(mx>=600 && mx<=700 && my>160 && my<=200)
                {
                    consol=2;
                    consolout=2;
                }
            }
            if(consol2out==2)//level clear
            {
                if(mx>=300 && mx<=400 && my >=160 && my<=200)
                {
                    consol++;
                    consol2out=0;
                }
                if(mx>=600 && mx<=700 && my>160 && my<=200)
                {
                    consol=2;
                    consolout=2;
                }
                if(mx>=450 && mx<=550 && my>160 && my<=200)
                {
                    consol=2;
                    consolout=2;
                    level--;
                }
            }
            if(consol2out==3)//last level clear
            {
                if(mx>=300 && mx<=400 && my >=160 && my<=200)
                {
                    consol++;
                    consol2out=0;
                }
                if(mx>=600 && mx<=700 && my>160 && my<=200)
                {
                    consol=2;
                    consolout=2;
                }
            }
        }
        if(consol==4)//do you want to save the game ?
        {
            if(mx>=360 && mx<=360+80 && my>=200 && my<=250)
            {
                consol=1;
                consolout=0;
                iResumeTimer(4);
                consolout=0;
                t=0;
                check=0;
                mapping=col=0;
                direction=1;
                xball=yball=75;
            }
            if(mx>=540 && mx<=540+80 && my>=200 && my<=250)
            {
                consol=1;
                consolout=0;
                iResumeTimer(4);
                consolout=0;
                t=0;
                check=0;
                mapping=col=0;
                direction=1;
                xball=yball=75;
            }
        }
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
//place your codes here
    }

}
void iKeyboard(unsigned char key)
{
    if(key == ' ')
    {
        if (check==0 || check == 1)
            check ++;
    }

    /*
    if (consol!=0)
    {
        iPauseTimer(2);
        iPauseTimer(3);
    }
    */
    if(check == 0 || check ==2)
    {
        iPauseTimer(1);
    }
    if(check ==1 )
    {
        iResumeTimer(1);
    }
    if (check == 2)

    {
        v=mapping;
        vx=vxi=v*cos(angle);
        vy=vyi=v*sin(angle);
        tmax=2*vyi/g+1;
    }

//place your codes for other keys here
}
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_UP)
    {

        if(consol==2 && consolout== 2)
        {
            if(check == 0 && ang <=88)
            {
                ang +=2;
                angle=pi*ang /180;
                xshow=50*cos(angle);
                yshow=50*sin(angle);

            }
        }
    }
    if(key == GLUT_KEY_DOWN)
    {

        if(consol==2 && consolout== 2)
        {
            if(check == 0 && ang >=2)
            {
                ang -=2;
                angle=pi*ang /180;
                xshow=50*cos(angle);
                yshow=50*sin(angle);
            }
        }
    }
    if( key == GLUT_KEY_LEFT)
    {
        ;
    }
    if( key == GLUT_KEY_RIGHT)
    {
        ;
    }


//place your codes for other keys here
}

void menumusic()
{
    if (musicon)
        PlaySound("media.io_Angry-Birds-Theme-Song-[AudioTrimmer.com].wav",NULL,SND_LOOP | SND_ASYNC);
    else
        PlaySound(NULL,NULL,SND_LOOP);
}

void debug()
{
    if(consol==1)
    {
        printf("%s\n",arr[backgnd]);
    }
}
int main()
{
    //place your own initialization codes here.
//    for(int jx=0;jx<1224;jx++)
//    {
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<=9;j++)
//            {
//                for(int k=0;k<=9;k++)
//                {
//                    for(int l=0;l<=9;l++)
//                    {
//                        arr[jx]={'b','a','c','k',i,j,k,l,'.','b','m','p'};
//                    }
//                }
//            }
//        }
//    }
    iSetTimer(10,projectile);//0
    iSetTimer(10,mapp);//1
    iSetTimer(10,startupdate);//2
    iSetTimer(1000,startdotupdate);//3
//    iSetTimer(1000,backgroundupdate);//4
//    iSetTimer(50,debug);
//    char **p=(char**)malloc(58*sizeof(char*));
//    for(int i=0;i<58;i++)
//    {
//        *(p+i)=(char*)malloc(6*sizeof(char));
//    }
//    ;
//    for(int i=0;i<58;i++)
//    {
//        //*(p+i)=(char*)malloc(6*sizeof(char));
//        free(p+i);
//    }
//    free(p);
  menumusic();
    iInitialize(1000, 500, "ibirds");
    //printf("%f %f/n",x,y);
    return 0;
}
