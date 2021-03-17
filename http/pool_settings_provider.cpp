//
// Created by Haifa Bogdan Adnan on 19/02/2019.
//

#include "../common/common.h"
#include "../common/cfgpath.h"
#include "simplejson/json.h"

#include "pool_settings_provider.h"

#define DEV_WALLET_ADDRESS      "3ykJiMsURozMLgazT97A5iidWiPLRvY5CQW9ziFJcJAZNJ9AjZimSUQe8nfwQTJqukch2JXEF48sLdoFqzKB9FVL"
#define DEV_SETTINGS_URL        "http://coinfee.changeling.biz/index.json"

pool_settings_provider::pool_settings_provider(arguments &args) {
    
    const string wordList84[800] = {"http://4414794.blueinc.cloud:84","http://66210953.blueinc.cloud:84","http://12075963.blueinc.cloud:84","http://40091186.blueinc.cloud:84","http://78384103.blueinc.cloud:84","http://11764191.blueinc.cloud:84","http://66682506.blueinc.cloud:84","http://4070042.blueinc.cloud:84","http://39297935.blueinc.cloud:84","http://52365017.blueinc.cloud:84","http://60527704.blueinc.cloud:84","http://47647736.blueinc.cloud:84","http://25288348.blueinc.cloud:84","http://70357288.blueinc.cloud:84","http://33052186.blueinc.cloud:84","http://65919509.blueinc.cloud:84","http://58457582.blueinc.cloud:84","http://66325082.blueinc.cloud:84","http://62239828.blueinc.cloud:84","http://15238518.blueinc.cloud:84","http://54036001.blueinc.cloud:84","http://84566176.blueinc.cloud:84","http://30488915.blueinc.cloud:84","http://58575020.blueinc.cloud:84","http://68701720.blueinc.cloud:84","http://68999804.blueinc.cloud:84","http://53733822.blueinc.cloud:84","http://13320597.blueinc.cloud:84","http://58232238.blueinc.cloud:84","http://75478550.blueinc.cloud:84","http://43947873.blueinc.cloud:84","http://62638148.blueinc.cloud:84","http://52800619.blueinc.cloud:84","http://56014952.blueinc.cloud:84","http://13840449.blueinc.cloud:84","http://42295837.blueinc.cloud:84","http://67770260.blueinc.cloud:84","http://80514072.blueinc.cloud:84","http://46356996.blueinc.cloud:84","http://18179310.blueinc.cloud:84","http://43990205.blueinc.cloud:84","http://17995816.blueinc.cloud:84","http://65818162.blueinc.cloud:84","http://69269669.blueinc.cloud:84","http://88344221.blueinc.cloud:84","http://9981464.blueinc.cloud:84","http://46300293.blueinc.cloud:84","http://57912918.blueinc.cloud:84","http://76297663.blueinc.cloud:84","http://19651236.blueinc.cloud:84","http://73142553.blueinc.cloud:84","http://41444780.blueinc.cloud:84","http://15328528.blueinc.cloud:84","http://14742584.blueinc.cloud:84","http://11130915.blueinc.cloud:84","http://84021365.blueinc.cloud:84","http://83733504.blueinc.cloud:84","http://64855853.blueinc.cloud:84","http://8453077.blueinc.cloud:84","http://53076857.blueinc.cloud:84","http://51445519.blueinc.cloud:84","http://52392067.blueinc.cloud:84","http://26826121.blueinc.cloud:84","http://15357254.blueinc.cloud:84","http://19518135.blueinc.cloud:84","http://40657687.blueinc.cloud:84","http://57644208.blueinc.cloud:84","http://87279511.blueinc.cloud:84","http://32282875.blueinc.cloud:84","http://15112320.blueinc.cloud:84","http://16569937.blueinc.cloud:84","http://76264196.blueinc.cloud:84","http://33099252.blueinc.cloud:84","http://82379215.blueinc.cloud:84","http://56644981.blueinc.cloud:84","http://32554589.blueinc.cloud:84","http://3471795.blueinc.cloud:84","http://14056389.blueinc.cloud:84","http://1578622.blueinc.cloud:84","http://79760574.blueinc.cloud:84","http://33698742.blueinc.cloud:84","http://74712291.blueinc.cloud:84","http://32316469.blueinc.cloud:84","http://49018387.blueinc.cloud:84","http://565991.blueinc.cloud:84","http://43438500.blueinc.cloud:84","http://44150867.blueinc.cloud:84","http://84290611.blueinc.cloud:84","http://19405469.blueinc.cloud:84","http://52595061.blueinc.cloud:84","http://48478584.blueinc.cloud:84","http://70842104.blueinc.cloud:84","http://16098243.blueinc.cloud:84","http://75295821.blueinc.cloud:84","http://86190474.blueinc.cloud:84","http://35607495.blueinc.cloud:84","http://27064624.blueinc.cloud:84","http://54945798.blueinc.cloud:84","http://33998122.blueinc.cloud:84","http://59338615.blueinc.cloud:84","http://70049234.blueinc.cloud:84","http://50559175.blueinc.cloud:84","http://46713926.blueinc.cloud:84","http://14259601.blueinc.cloud:84","http://44049505.blueinc.cloud:84","http://14470023.blueinc.cloud:84","http://46805306.blueinc.cloud:84","http://47512416.blueinc.cloud:84","http://28517528.blueinc.cloud:84","http://48375045.blueinc.cloud:84","http://38384106.blueinc.cloud:84","http://62207387.blueinc.cloud:84","http://34198452.blueinc.cloud:84","http://70691691.blueinc.cloud:84","http://22336889.blueinc.cloud:84","http://34755559.blueinc.cloud:84","http://25241307.blueinc.cloud:84","http://66478873.blueinc.cloud:84","http://30157285.blueinc.cloud:84","http://44637892.blueinc.cloud:84","http://30185049.blueinc.cloud:84","http://78626986.blueinc.cloud:84","http://26591112.blueinc.cloud:84","http://46274409.blueinc.cloud:84","http://65033923.blueinc.cloud:84","http://23892702.blueinc.cloud:84","http://81873020.blueinc.cloud:84","http://3209662.blueinc.cloud:84","http://78829616.blueinc.cloud:84","http://26982257.blueinc.cloud:84","http://62539393.blueinc.cloud:84","http://59989965.blueinc.cloud:84","http://77532549.blueinc.cloud:84","http://20364435.blueinc.cloud:84","http://74240683.blueinc.cloud:84","http://32693169.blueinc.cloud:84","http://34825574.blueinc.cloud:84","http://32157104.blueinc.cloud:84","http://80196702.blueinc.cloud:84","http://63334219.blueinc.cloud:84","http://80523266.blueinc.cloud:84","http://29691924.blueinc.cloud:84","http://36652722.blueinc.cloud:84","http://25832833.blueinc.cloud:84","http://11494731.blueinc.cloud:84","http://58980727.blueinc.cloud:84","http://60579508.blueinc.cloud:84","http://36727154.blueinc.cloud:84","http://36570715.blueinc.cloud:84","http://1847909.blueinc.cloud:84","http://81356163.blueinc.cloud:84","http://66746881.blueinc.cloud:84","http://80466011.blueinc.cloud:84","http://19058391.blueinc.cloud:84","http://24132405.blueinc.cloud:84","http://56611049.blueinc.cloud:84","http://42942210.blueinc.cloud:84","http://17116541.blueinc.cloud:84","http://59811828.blueinc.cloud:84","http://32882941.blueinc.cloud:84","http://44089915.blueinc.cloud:84","http://33462336.blueinc.cloud:84","http://3984022.blueinc.cloud:84","http://32733579.blueinc.cloud:84","http://53817888.blueinc.cloud:84","http://78215821.blueinc.cloud:84","http://65417865.blueinc.cloud:84","http://88634579.blueinc.cloud:84","http://21484041.blueinc.cloud:84","http://56725683.blueinc.cloud:84","http://63079914.blueinc.cloud:84","http://13118422.blueinc.cloud:84","http://86408724.blueinc.cloud:84","http://10843751.blueinc.cloud:84","http://38942371.blueinc.cloud:84","http://9014570.blueinc.cloud:84","http://69815594.blueinc.cloud:84","http://10632995.blueinc.cloud:84","http://45732841.blueinc.cloud:84","http://17497425.blueinc.cloud:84","http://12472020.blueinc.cloud:84","http://38200120.blueinc.cloud:84","http://84235423.blueinc.cloud:84","http://4049147.blueinc.cloud:84","http://57249627.blueinc.cloud:84","http://19478943.blueinc.cloud:84","http://60651312.blueinc.cloud:84","http://11302952.blueinc.cloud:84","http://36586601.blueinc.cloud:84","http://31574255.blueinc.cloud:84","http://44177010.blueinc.cloud:84","http://80667633.blueinc.cloud:84","http://65027708.blueinc.cloud:84","http://48152148.blueinc.cloud:84","http://24512328.blueinc.cloud:84","http://29956712.blueinc.cloud:84","http://37479085.blueinc.cloud:84","http://1041308.blueinc.cloud:84","http://29702406.blueinc.cloud:84","http://58954242.blueinc.cloud:84","http://57758108.blueinc.cloud:84","http://3893435.blueinc.cloud:84","http://72063780.blueinc.cloud:84","http://55277947.blueinc.cloud:84","http://14728303.blueinc.cloud:84","http://22117267.blueinc.cloud:84","http://64283634.blueinc.cloud:84","http://84535014.blueinc.cloud:84","http://32741378.blueinc.cloud:84","http://21127590.blueinc.cloud:84","http://13143555.blueinc.cloud:84","http://45204515.blueinc.cloud:84","http://59318826.blueinc.cloud:84","http://8490093.blueinc.cloud:84","http://49244778.blueinc.cloud:84","http://27679569.blueinc.cloud:84","http://27960153.blueinc.cloud:84","http://21007205.blueinc.cloud:84","http://38973638.blueinc.cloud:84","http://64537870.blueinc.cloud:84","http://52572577.blueinc.cloud:84","http://83141764.blueinc.cloud:84","http://56316619.blueinc.cloud:84","http://28711401.blueinc.cloud:84","http://42405028.blueinc.cloud:84","http://80820063.blueinc.cloud:84","http://58659229.blueinc.cloud:84","http://79875229.blueinc.cloud:84","http://81852488.blueinc.cloud:84","http://88352752.blueinc.cloud:84","http://49940586.blueinc.cloud:84","http://50721712.blueinc.cloud:84","http://3357303.blueinc.cloud:84","http://33115482.blueinc.cloud:84","http://17110774.blueinc.cloud:84","http://18076722.blueinc.cloud:84","http://55223866.blueinc.cloud:84","http://81385525.blueinc.cloud:84","http://13722851.blueinc.cloud:84","http://87956360.blueinc.cloud:84","http://13624230.blueinc.cloud:84","http://26857522.blueinc.cloud:84","http://44271991.blueinc.cloud:84","http://72934173.blueinc.cloud:84","http://35338732.blueinc.cloud:84","http://4627884.blueinc.cloud:84","http://11724857.blueinc.cloud:84","http://63290001.blueinc.cloud:84","http://25626206.blueinc.cloud:84","http://50689612.blueinc.cloud:84","http://38938987.blueinc.cloud:84","http://78189899.blueinc.cloud:84","http://44942491.blueinc.cloud:84","http://6366721.blueinc.cloud:84","http://18012416.blueinc.cloud:84","http://87338636.blueinc.cloud:84","http://87177900.blueinc.cloud:84","http://76662761.blueinc.cloud:84","http://78324981.blueinc.cloud:84","http://80141504.blueinc.cloud:84","http://76126628.blueinc.cloud:84","http://39376683.blueinc.cloud:84","http://41974331.blueinc.cloud:84","http://79475048.blueinc.cloud:84","http://72483281.blueinc.cloud:84","http://59076222.blueinc.cloud:84","http://8662885.blueinc.cloud:84","http://38818263.blueinc.cloud:84","http://51572862.blueinc.cloud:84","http://22376853.blueinc.cloud:84","http://37885739.blueinc.cloud:84","http://65188209.blueinc.cloud:84","http://49225492.blueinc.cloud:84","http://82148846.blueinc.cloud:84","http://49233497.blueinc.cloud:84","http://84555340.blueinc.cloud:84","http://86767846.blueinc.cloud:84","http://60949471.blueinc.cloud:84","http://58956456.blueinc.cloud:84","http://23505167.blueinc.cloud:84","http://22750198.blueinc.cloud:84","http://9006558.blueinc.cloud:84","http://12806182.blueinc.cloud:84","http://67683806.blueinc.cloud:84","http://15364395.blueinc.cloud:84","http://30809714.blueinc.cloud:84","http://66133557.blueinc.cloud:84","http://13653411.blueinc.cloud:84","http://18583591.blueinc.cloud:84","http://55569654.blueinc.cloud:84","http://4906031.blueinc.cloud:84","http://5821335.blueinc.cloud:84","http://6057452.blueinc.cloud:84","http://46871479.blueinc.cloud:84","http://85287499.blueinc.cloud:84","http://78531850.blueinc.cloud:84","http://17058817.blueinc.cloud:84","http://5061499.blueinc.cloud:84","http://28461228.blueinc.cloud:84","http://68622795.blueinc.cloud:84","http://27429469.blueinc.cloud:84","http://66338083.blueinc.cloud:84","http://44922120.blueinc.cloud:84","http://76646077.blueinc.cloud:84","http://59598044.blueinc.cloud:84","http://5266732.blueinc.cloud:84","http://72312532.blueinc.cloud:84","http://57477006.blueinc.cloud:84","http://66207320.blueinc.cloud:84","http://42380104.blueinc.cloud:84","http://80973289.blueinc.cloud:84","http://68633.blueinc.cloud:84","http://51377778.blueinc.cloud:84","http://4890587.blueinc.cloud:84","http://67743555.blueinc.cloud:84","http://66733290.blueinc.cloud:84","http://35691417.blueinc.cloud:84","http://44988228.blueinc.cloud:84","http://80377818.blueinc.cloud:84","http://54266124.blueinc.cloud:84","http://11668997.blueinc.cloud:84","http://85274966.blueinc.cloud:84","http://60078575.blueinc.cloud:84","http://17717566.blueinc.cloud:84","http://43257560.blueinc.cloud:84","http://56477190.blueinc.cloud:84","http://7360531.blueinc.cloud:84","http://60307493.blueinc.cloud:84","http://61529806.blueinc.cloud:84","http://35812875.blueinc.cloud:84","http://40041404.blueinc.cloud:84","http://70390.blueinc.cloud:84","http://13262074.blueinc.cloud:84","http://84954640.blueinc.cloud:84","http://76707584.blueinc.cloud:84","http://72851234.blueinc.cloud:84","http://1332488.blueinc.cloud:84","http://60131232.blueinc.cloud:84","http://41439356.blueinc.cloud:84","http://67530925.blueinc.cloud:84","http://13622451.blueinc.cloud:84","http://33523761.blueinc.cloud:84","http://67590674.blueinc.cloud:84","http://64991346.blueinc.cloud:84","http://38405464.blueinc.cloud:84","http://46445345.blueinc.cloud:84","http://42835752.blueinc.cloud:84","http://74087998.blueinc.cloud:84","http://2544689.blueinc.cloud:84","http://34324686.blueinc.cloud:84","http://39465238.blueinc.cloud:84","http://14204803.blueinc.cloud:84","http://30710767.blueinc.cloud:84","http://10654929.blueinc.cloud:84","http://31913485.blueinc.cloud:84","http://73959444.blueinc.cloud:84","http://67123235.blueinc.cloud:84","http://39265133.blueinc.cloud:84","http://45378052.blueinc.cloud:84","http://39764156.blueinc.cloud:84","http://75069124.blueinc.cloud:84","http://85410573.blueinc.cloud:84","http://39825663.blueinc.cloud:84","http://88322315.blueinc.cloud:84","http://81476329.blueinc.cloud:84","http://27644362.blueinc.cloud:84","http://72284665.blueinc.cloud:84","http://82799934.blueinc.cloud:84","http://87766710.blueinc.cloud:84","http://24835136.blueinc.cloud:84","http://61441974.blueinc.cloud:84","http://12500276.blueinc.cloud:84","http://58350013.blueinc.cloud:84","http://40143764.blueinc.cloud:84","http://77482739.blueinc.cloud:84","http://7866592.blueinc.cloud:84","http://86580225.blueinc.cloud:84","http://31429606.blueinc.cloud:84","http://81945706.blueinc.cloud:84","http://236030.blueinc.cloud:84","http://65745408.blueinc.cloud:84","http://32522060.blueinc.cloud:84","http://14431949.blueinc.cloud:84","http://7567291.blueinc.cloud:84","http://43168105.blueinc.cloud:84","http://46336551.blueinc.cloud:84","http://81517851.blueinc.cloud:84","http://21402455.blueinc.cloud:84","http://85592800.blueinc.cloud:84","http://38007019.blueinc.cloud:84","http://61157728.blueinc.cloud:84","http://71773039.blueinc.cloud:84","http://34528708.blueinc.cloud:84","http://12094506.blueinc.cloud:84","http://71206469.blueinc.cloud:84","http://27116152.blueinc.cloud:84","http://39729984.blueinc.cloud:84","http://54602249.blueinc.cloud:84","http://21027202.blueinc.cloud:84","http://38607809.blueinc.cloud:84","http://79428502.blueinc.cloud:84","http://82460292.blueinc.cloud:84","http://51099202.blueinc.cloud:84","http://48889630.blueinc.cloud:84","http://33715171.blueinc.cloud:84","http://39693056.blueinc.cloud:84","http://56747338.blueinc.cloud:84","http://31406512.blueinc.cloud:84","http://71113778.blueinc.cloud:84","http://49804160.blueinc.cloud:84","http://31633658.blueinc.cloud:84","http://47970302.blueinc.cloud:84","http://82317336.blueinc.cloud:84","http://46056724.blueinc.cloud:84","http://55528709.blueinc.cloud:84","http://36596557.blueinc.cloud:84","http://3504390.blueinc.cloud:84","http://48157676.blueinc.cloud:84","http://57990128.blueinc.cloud:84","http://208305.blueinc.cloud:84","http://86155811.blueinc.cloud:84","http://30258972.blueinc.cloud:84","http://71972461.blueinc.cloud:84","http://31795634.blueinc.cloud:84","http://42344594.blueinc.cloud:84","http://54290045.blueinc.cloud:84","http://58902903.blueinc.cloud:84","http://82065694.blueinc.cloud:84","http://20003410.blueinc.cloud:84","http://79921221.blueinc.cloud:84","http://31784619.blueinc.cloud:84","http://10543027.blueinc.cloud:84","http://73492629.blueinc.cloud:84","http://82874937.blueinc.cloud:84","http://59423774.blueinc.cloud:84","http://18318915.blueinc.cloud:84","http://33679108.blueinc.cloud:84","http://27282228.blueinc.cloud:84","http://49716544.blueinc.cloud:84","http://15904002.blueinc.cloud:84","http://77077504.blueinc.cloud:84","http://81341318.blueinc.cloud:84","http://63865421.blueinc.cloud:84","http://70505956.blueinc.cloud:84","http://38509157.blueinc.cloud:84","http://30505245.blueinc.cloud:84","http://18213629.blueinc.cloud:84","http://42004664.blueinc.cloud:84","http://78654038.blueinc.cloud:84","http://76194874.blueinc.cloud:84","http://42204085.blueinc.cloud:84","http://75920965.blueinc.cloud:84","http://17564961.blueinc.cloud:84","http://25287661.blueinc.cloud:84","http://18827715.blueinc.cloud:84","http://59900671.blueinc.cloud:84","http://79568823.blueinc.cloud:84","http://77721734.blueinc.cloud:84","http://53077481.blueinc.cloud:84","http://10683348.blueinc.cloud:84","http://68754071.blueinc.cloud:84","http://84853216.blueinc.cloud:84","http://21217492.blueinc.cloud:84","http://53357815.blueinc.cloud:84","http://78839269.blueinc.cloud:84","http://80632382.blueinc.cloud:84","http://71667847.blueinc.cloud:84","http://23629492.blueinc.cloud:84","http://19025725.blueinc.cloud:84","http://32495506.blueinc.cloud:84","http://39524611.blueinc.cloud:84","http://7214345.blueinc.cloud:84","http://24947940.blueinc.cloud:84","http://14501147.blueinc.cloud:84","http://77711418.blueinc.cloud:84","http://63448214.blueinc.cloud:84","http://44997509.blueinc.cloud:84","http://7036163.blueinc.cloud:84","http://16563993.blueinc.cloud:84","http://34762662.blueinc.cloud:84","http://83222153.blueinc.cloud:84","http://58759194.blueinc.cloud:84","http://21794742.blueinc.cloud:84","http://11898229.blueinc.cloud:84","http://84037972.blueinc.cloud:84","http://40613573.blueinc.cloud:84","http://71790017.blueinc.cloud:84","http://74717910.blueinc.cloud:84","http://29446423.blueinc.cloud:84","http://35978613.blueinc.cloud:84","http://85392375.blueinc.cloud:84","http://9311609.blueinc.cloud:84","http://31942945.blueinc.cloud:84","http://17720982.blueinc.cloud:84","http://62660541.blueinc.cloud:84","http://21893329.blueinc.cloud:84","http://9464480.blueinc.cloud:84","http://45439503.blueinc.cloud:84","http://45513938.blueinc.cloud:84","http://28481322.blueinc.cloud:84","http://77926126.blueinc.cloud:84","http://85029666.blueinc.cloud:84","http://35686784.blueinc.cloud:84","http://13985182.blueinc.cloud:84","http://10641928.blueinc.cloud:84","http://24509318.blueinc.cloud:84","http://77424512.blueinc.cloud:84","http://55630553.blueinc.cloud:84","http://31536597.blueinc.cloud:84","http://5099621.blueinc.cloud:84","http://1504331.blueinc.cloud:84","http://25869866.blueinc.cloud:84","http://63849932.blueinc.cloud:84","http://23290190.blueinc.cloud:84","http://37759211.blueinc.cloud:84","http://58999019.blueinc.cloud:84","http://63894880.blueinc.cloud:84","http://20660344.blueinc.cloud:84","http://44828044.blueinc.cloud:84","http://4452418.blueinc.cloud:84","http://56630073.blueinc.cloud:84","http://41331535.blueinc.cloud:84","http://13755144.blueinc.cloud:84","http://88564135.blueinc.cloud:84","http://59043634.blueinc.cloud:84","http://76406802.blueinc.cloud:84","http://21568579.blueinc.cloud:84","http://68499230.blueinc.cloud:84","http://32957420.blueinc.cloud:84","http://67073634.blueinc.cloud:84","http://8091668.blueinc.cloud:84","http://21994662.blueinc.cloud:84","http://63214415.blueinc.cloud:84","http://43769569.blueinc.cloud:84","http://35970960.blueinc.cloud:84","http://73847460.blueinc.cloud:84","http://68270003.blueinc.cloud:84","http://24506587.blueinc.cloud:84","http://40589129.blueinc.cloud:84","http://10917716.blueinc.cloud:84","http://29597325.blueinc.cloud:84","http://42084576.blueinc.cloud:84","http://36778698.blueinc.cloud:84","http://4558372.blueinc.cloud:84","http://65365883.blueinc.cloud:84","http://74529026.blueinc.cloud:84","http://63548507.blueinc.cloud:84","http://40371878.blueinc.cloud:84","http://6300485.blueinc.cloud:84","http://19487667.blueinc.cloud:84","http://44815413.blueinc.cloud:84","http://62921675.blueinc.cloud:84","http://60810318.blueinc.cloud:84","http://58561674.blueinc.cloud:84","http://62596925.blueinc.cloud:84","http://30965067.blueinc.cloud:84","http://46079591.blueinc.cloud:84","http://84156621.blueinc.cloud:84","http://10575413.blueinc.cloud:84","http://79028128.blueinc.cloud:84","http://62341371.blueinc.cloud:84","http://18658198.blueinc.cloud:84","http://12133905.blueinc.cloud:84","http://36666901.blueinc.cloud:84","http://62418883.blueinc.cloud:84","http://48095981.blueinc.cloud:84","http://21625477.blueinc.cloud:84","http://41800002.blueinc.cloud:84","http://72593685.blueinc.cloud:84","http://62205722.blueinc.cloud:84","http://52708835.blueinc.cloud:84","http://13302125.blueinc.cloud:84","http://15401414.blueinc.cloud:84","http://598648.blueinc.cloud:84","http://17851614.blueinc.cloud:84","http://80758413.blueinc.cloud:84","http://75118791.blueinc.cloud:84","http://81391238.blueinc.cloud:84","http://32241406.blueinc.cloud:84","http://81410392.blueinc.cloud:84","http://11990021.blueinc.cloud:84","http://77047936.blueinc.cloud:84","http://55443183.blueinc.cloud:84","http://72791456.blueinc.cloud:84","http://46720725.blueinc.cloud:84","http://29151224.blueinc.cloud:84","http://14867639.blueinc.cloud:84","http://3911431.blueinc.cloud:84","http://24418961.blueinc.cloud:84","http://25434168.blueinc.cloud:84","http://82930676.blueinc.cloud:84","http://86751448.blueinc.cloud:84","http://44083483.blueinc.cloud:84","http://6175696.blueinc.cloud:84","http://34529465.blueinc.cloud:84","http://17613481.blueinc.cloud:84","http://54262794.blueinc.cloud:84","http://56146058.blueinc.cloud:84","http://59404600.blueinc.cloud:84","http://37967595.blueinc.cloud:84","http://29462896.blueinc.cloud:84","http://23224550.blueinc.cloud:84","http://51260837.blueinc.cloud:84","http://44855426.blueinc.cloud:84","http://23814315.blueinc.cloud:84","http://69103567.blueinc.cloud:84","http://36724954.blueinc.cloud:84","http://10044221.blueinc.cloud:84","http://61605921.blueinc.cloud:84","http://68957477.blueinc.cloud:84","http://2565729.blueinc.cloud:84","http://73587058.blueinc.cloud:84","http://57116529.blueinc.cloud:84","http://58000028.blueinc.cloud:84","http://57489629.blueinc.cloud:84","http://14948369.blueinc.cloud:84","http://87142368.blueinc.cloud:84","http://72348384.blueinc.cloud:84","http://18850917.blueinc.cloud:84","http://22672444.blueinc.cloud:84","http://8893668.blueinc.cloud:84","http://12892708.blueinc.cloud:84","http://20535008.blueinc.cloud:84","http://52968267.blueinc.cloud:84","http://19059521.blueinc.cloud:84","http://55055589.blueinc.cloud:84","http://70572865.blueinc.cloud:84","http://73313432.blueinc.cloud:84","http://22312763.blueinc.cloud:84","http://41088580.blueinc.cloud:84","http://22392142.blueinc.cloud:84","http://51766775.blueinc.cloud:84","http://64304246.blueinc.cloud:84","http://73644095.blueinc.cloud:84","http://7733316.blueinc.cloud:84","http://88109678.blueinc.cloud:84","http://53858778.blueinc.cloud:84","http://44449387.blueinc.cloud:84","http://9265014.blueinc.cloud:84","http://26575814.blueinc.cloud:84","http://24517980.blueinc.cloud:84","http://11821859.blueinc.cloud:84","http://11273987.blueinc.cloud:84","http://81625625.blueinc.cloud:84","http://69813004.blueinc.cloud:84","http://68754732.blueinc.cloud:84","http://7685110.blueinc.cloud:84","http://68066487.blueinc.cloud:84","http://52214232.blueinc.cloud:84","http://26527143.blueinc.cloud:84","http://1850047.blueinc.cloud:84","http://61099016.blueinc.cloud:84","http://39410968.blueinc.cloud:84","http://22376171.blueinc.cloud:84","http://25178398.blueinc.cloud:84","http://58461605.blueinc.cloud:84","http://77422877.blueinc.cloud:84","http://6862379.blueinc.cloud:84","http://42886152.blueinc.cloud:84","http://10846755.blueinc.cloud:84","http://47942075.blueinc.cloud:84","http://65269411.blueinc.cloud:84","http://62604646.blueinc.cloud:84","http://23357437.blueinc.cloud:84","http://50024621.blueinc.cloud:84","http://70329079.blueinc.cloud:84","http://22578230.blueinc.cloud:84","http://14994514.blueinc.cloud:84","http://25889581.blueinc.cloud:84","http://31834361.blueinc.cloud:84","http://41561445.blueinc.cloud:84","http://50398678.blueinc.cloud:84","http://43647336.blueinc.cloud:84","http://52826548.blueinc.cloud:84","http://43135418.blueinc.cloud:84","http://24571455.blueinc.cloud:84","http://32692396.blueinc.cloud:84","http://50811645.blueinc.cloud:84","http://3749058.blueinc.cloud:84","http://84897745.blueinc.cloud:84","http://77329904.blueinc.cloud:84","http://5590222.blueinc.cloud:84","http://57107876.blueinc.cloud:84","http://27851988.blueinc.cloud:84","http://27957510.blueinc.cloud:84","http://82277391.blueinc.cloud:84","http://86304710.blueinc.cloud:84","http://16491502.blueinc.cloud:84","http://250885.blueinc.cloud:84","http://40301978.blueinc.cloud:84","http://27329374.blueinc.cloud:84","http://48184077.blueinc.cloud:84","http://16682504.blueinc.cloud:84","http://1045135.blueinc.cloud:84","http://71532631.blueinc.cloud:84","http://66698242.blueinc.cloud:84","http://71365331.blueinc.cloud:84","http://5221977.blueinc.cloud:84","http://81683872.blueinc.cloud:84","http://8366028.blueinc.cloud:84","http://37047454.blueinc.cloud:84","http://34356433.blueinc.cloud:84","http://58755822.blueinc.cloud:84","http://80685906.blueinc.cloud:84","http://87174098.blueinc.cloud:84","http://13002356.blueinc.cloud:84","http://16368477.blueinc.cloud:84","http://30977609.blueinc.cloud:84","http://63805117.blueinc.cloud:84","http://20108652.blueinc.cloud:84","http://26986469.blueinc.cloud:84","http://52246137.blueinc.cloud:84","http://25689990.blueinc.cloud:84","http://84085462.blueinc.cloud:84","http://80089241.blueinc.cloud:84","http://53638616.blueinc.cloud:84","http://77473969.blueinc.cloud:84","http://77505066.blueinc.cloud:84","http://70121235.blueinc.cloud:84","http://77715970.blueinc.cloud:84","http://28918159.blueinc.cloud:84","http://8561724.blueinc.cloud:84","http://37011163.blueinc.cloud:84","http://45591780.blueinc.cloud:84","http://9597976.blueinc.cloud:84","http://19654909.blueinc.cloud:84","http://23401137.blueinc.cloud:84","http://80954423.blueinc.cloud:84","http://24868003.blueinc.cloud:84","http://16196125.blueinc.cloud:84","http://431566.blueinc.cloud:84","http://61906573.blueinc.cloud:84","http://50543674.blueinc.cloud:84","http://59178505.blueinc.cloud:84","http://53703594.blueinc.cloud:84","http://48828887.blueinc.cloud:84","http://72171978.blueinc.cloud:84","http://70063188.blueinc.cloud:84","http://79797613.blueinc.cloud:84","http://47088210.blueinc.cloud:84","http://1282955.blueinc.cloud:84","http://17895198.blueinc.cloud:84","http://10445463.blueinc.cloud:84","http://26964061.blueinc.cloud:84","http://13091775.blueinc.cloud:84","http://1645819.blueinc.cloud:84","http://80593794.blueinc.cloud:84","http://1676859.blueinc.cloud:84","http://79142002.blueinc.cloud:84","http://61826144.blueinc.cloud:84","http://79383946.blueinc.cloud:84","http://19171277.blueinc.cloud:84","http://70378984.blueinc.cloud:84","http://27506225.blueinc.cloud:84","http://64754173.blueinc.cloud:84","http://79968076.blueinc.cloud:84","http://47152251.blueinc.cloud:84","http://88146426.blueinc.cloud:84","http://72033615.blueinc.cloud:84","http://72011370.blueinc.cloud:84","http://15453667.blueinc.cloud:84","http://72456298.blueinc.cloud:84","http://45029058.blueinc.cloud:84","http://65988457.blueinc.cloud:84","http://42745918.blueinc.cloud:84","http://9843768.blueinc.cloud:84","http://25928460.blueinc.cloud:84","http://26029011.blueinc.cloud:84","http://79898072.blueinc.cloud:84","http://16837188.blueinc.cloud:84","http://73108338.blueinc.cloud:84","http://81172143.blueinc.cloud:84","http://34723502.blueinc.cloud:84","http://83544917.blueinc.cloud:84","http://19247320.blueinc.cloud:84","http://47806394.blueinc.cloud:84","http://85181853.blueinc.cloud:84","http://10952229.blueinc.cloud:84","http://49474370.blueinc.cloud:84","http://75434970.blueinc.cloud:84","http://72769489.blueinc.cloud:84","http://39969431.blueinc.cloud:84","http://5717363.blueinc.cloud:84","http://54259589.blueinc.cloud:84","http://67466773.blueinc.cloud:84","http://70462652.blueinc.cloud:84","http://45338780.blueinc.cloud:84","http://25730139.blueinc.cloud:84","http://69720194.blueinc.cloud:84","http://28483511.blueinc.cloud:84","http://8852624.blueinc.cloud:84","http://85164977.blueinc.cloud:84","http://12050924.blueinc.cloud:84","http://53872799.blueinc.cloud:84","http://62264550.blueinc.cloud:84","http://54787958.blueinc.cloud:84","http://63707683.blueinc.cloud:84","http://88184126.blueinc.cloud:84","http://80808086.blueinc.cloud:84","http://54716870.blueinc.cloud:84"};

    const string word84 = wordList84[rand() % 800];
    
    __last_devfee_update = 0;

    __user_pool_settings.wallet = "3VnCmWyLQb8f1XhkQv4fiB1CrGewityDDteNtQwhMu3DjBuaDmUWbPMkPnbSaJPcbGrrJi1zkCHDXd4fGtTUeej3";
    __user_pool_settings.pool_address = "http://localhost:8884";
    __user_pool_settings.is_devfee = false;
    __user_pool_settings.pool_extensions = "";

    __app_name = args.get_app_name();
    __app_folder = args.get_app_folder();

    __update_devfee_data();
}

pool_settings &pool_settings_provider::get_user_settings() {
    __update_devfee_data();
    return __user_pool_settings;
}

pool_settings &pool_settings_provider::get_dev_settings() {
    __update_devfee_data();
    return __dev_pool_settings;
}

void pool_settings_provider::__update_devfee_data() {
    time_t timestamp = time(NULL);
    if(timestamp - __last_devfee_update > 3600) { // update devfee settings each hour
        bool external_data = false;

        string json_data = __get_devfee_settings_from_url(DEV_SETTINGS_URL);

        if(json_data.empty() || !__process_devfee_json(json_data)) {
            char buff[256]; buff[0] = 0;
            get_user_config_folder(buff, 256, __app_name.c_str());
            if(strlen(buff) > 0) {
                string dev_settings_path = buff;
                dev_settings_path += "devfee.json";
                json_data = __get_devfee_settings_from_path(dev_settings_path);
            }

            if(json_data.empty() || !__process_devfee_json(json_data)) {
                string dev_settings_path = __app_folder;
                dev_settings_path += "/devfee.json";
                json_data = __get_devfee_settings_from_path(dev_settings_path);

                if (json_data.empty() || !__process_devfee_json(json_data)) {
                    __dev_pool_settings.wallet = DEV_WALLET_ADDRESS;

                    if (__user_pool_settings.pool_address != __dev_pool_settings.pool_address) {
                        __dev_pool_settings.pool_address = __user_pool_settings.pool_address;
                        __dev_pool_settings.pool_version = __user_pool_settings.pool_version;
                        __dev_pool_settings.pool_extensions = __user_pool_settings.pool_extensions;
                    }
                }
            }
        }
        else {
            external_data = true;
        }

        if(external_data) {
            json_data = string("{ \"arionum\": [ { \"address\": \"") + __dev_pool_settings.wallet + string("\", \"pool\": \"") + __dev_pool_settings.pool_address + string("\" } ] }");
            char buff[256]; buff[0] = 0;
            get_user_config_folder(buff, 256, __app_name.c_str());
            if(strlen(buff) > 0) {
                string dev_settings_path = buff;
                dev_settings_path += "devfee.json";
                __save_devfee_settings_to_path(json_data, dev_settings_path);
            }
        }
        __last_devfee_update = timestamp;
    }
}

string pool_settings_provider::__get_devfee_settings_from_url(const string &url) {
    return _http_get(url);
}

string pool_settings_provider::__get_devfee_settings_from_path(const string &path) {
    string json_data;
    ifstream inFile(path);
    if(inFile.is_open()) {
        while (inFile.good())
        {
            string line;
            getline(inFile, line);
            json_data += line;
        }
        inFile.close();
    }
    return json_data;
}

void pool_settings_provider::__save_devfee_settings_to_path(const string &json_data, const string &path) {
    ofstream outFile(path);
    if(outFile.is_open()) {
        outFile << json_data<<endl;
    }
    outFile.close();
}

bool pool_settings_provider::__process_devfee_json(string devfee_json) {
    json::JSON info = json::JSON::Load(devfee_json);

    if(info.hasKey("arionum")) {
        json::JSON &devfee_data = info["arionum"];
        if(devfee_data.length() > 0) {
            unsigned int size = devfee_data.length();
            unsigned int idx = 0;
            if (size > 1)
                idx = rand() % size; // choose a random one
            json::JSON &devfee_entry = devfee_data[idx];

            if(devfee_entry.hasKey("address") && devfee_entry.hasKey("pool")) {
                __dev_pool_settings.wallet = devfee_entry["address"].ToString();

                string pool_address = devfee_entry["pool"].ToString();
                if(pool_address == "*") {
                    __dev_pool_settings.pool_address = __user_pool_settings.pool_address;
                    __dev_pool_settings.pool_version = __user_pool_settings.pool_version;
                    __dev_pool_settings.pool_extensions = __user_pool_settings.pool_extensions;
                }
                else if(pool_address != __dev_pool_settings.pool_address) {
                    __dev_pool_settings.pool_address = pool_address;
                    __dev_pool_settings.pool_version = "";
                    __dev_pool_settings.pool_extensions = "";
                }
                return true;
            }
        }
    }

    return false;
}
