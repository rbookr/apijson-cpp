#include "ServerGet2.h"
#include <string_view>
#include <iostream>

const std::string ServerGet2::TAG = "ServerGet2   ";
json ServerGet2::getObject(
        std::string parentPath,     //父路径
        QueryConfig parentConfig,   //querConfig
        std::string name,           // name : {}
        json request                // 请求的json
        ){

    //const static std::string_view TAG = "hello world";

    if( !request.size()) return json(); //空

    std::string path = getPath(parentPath,name);

    // TODO explain
    QueryConfig config = isNumber(name) ? parentConfig :
        QueryConfig(name); // table_name
    
    bool nameIsNumber = isNumber(name);
    int position = nameIsNumber ? std::atoi(name.c_str()) :0;

    bool containRelation = false; //是否包含相对路径关系


    json transferredRequest = json(); // 新的json 传转化后的json
    if( request.size() != 0 ){ //请求不空
        std::string value;
        json child;
        json result;
        bool isFirst = true;
        for( auto& el : request.items()){
            auto key = el.key();
            auto val = el.value();
            //std::cout << "key " << key << " ";
            //std::cout << "value " << val << " " << std::endl;
            debug_out(TAG,"遍历 request :","key ",key," <==> value ",val);
            //continue;
            //TODO 边界条件
            if( val.is_null()  || (!val.is_object() && !val.is_array() ) ){
                transferredRequest[key] = val ;
                //TODO isPath
                
                // if(val.is_string() && isPath( val ) )
                std::cout << "bian jie " << std::endl;
                std::cout << transferredRequest <<std::endl;
            }
            else {
                if( isArrayKey(key)){
                    //TODO
                    std::cout << "do nothing, array key : " << name << std::endl;
                }
                else { //不是Array key
                    isFirst = false; // ?
                    result = getObject(path, config, key, val);
                }
                debug_out(TAG," ","getObject key = ",key,"  result = ",result);
                if( result.is_null() == false){
                    transferredRequest[key] = result;
                }
            }
        }

        debug_out(TAG,name);
        debug_out(TAG,isObjectKey(name));
        if(containRelation == false && isObjectKey(name)) { //不包含 相对路径 且 是普通名字
            if( parseRelation == false ||  false /*isInRelationMap(path)*/){ // 不用解析 parseRelation
                debug_out(TAG,name,"  ----- 开始解析SQL ",transferredRequest);
                QueryConfig config2 = getQueryConfig(name,transferredRequest);

                //if( parentConfig == nullptr ){

                //}
                json result = getSQLObject(config2);
                transferredRequest = result;

                //if(parseRelation)
            }
        }

        return transferredRequest;
    }
    return {};
}

QueryConfig ServerGet2::getQueryConfig(std::string table,json request){
    return QueryConfig::getQueryConfig(table, request);
}

json ServerGet2::getSQLObject(QueryConfig config) {
    return json();
}
