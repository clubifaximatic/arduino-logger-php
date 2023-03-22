<?php
class SampleController extends BaseController
{
    /** 
     * "/sample/list" Endpoint - Get list of users 
     */
    public function listAction()
    {
        $strErrorDesc = '';
        $requestMethod = $_SERVER["REQUEST_METHOD"];
        $arrQueryStringParams = $this->getQueryStringParams();
        if (strtoupper($requestMethod) == 'GET') {
            try {
                $sampleModel = new SampleModel();
                $intLimit = 10;
                if (isset($arrQueryStringParams['limit']) && $arrQueryStringParams['limit']) {
                    $intLimit = $arrQueryStringParams['limit'];
                }
                error_log($intLimit);
                $response = $sampleModel->list($intLimit);
                $responseData = "id,timestamp,CO2_1,CO2_2,CO2_3,CO2_4,CO2_5,CO2_6,O2_1,O2_2,O2_3,O2_4,O2_5,O2_6,\n";
                $responseData .= implode("\n", $response);
                // $responseData = json_encode($response);;
            } catch (Error $e) {
                $strErrorDesc = $e->getMessage().'Something went wrong! Please contact support.';
                $strErrorHeader = 'HTTP/1.1 500 Internal Server Error';
            }
        } else {
            $strErrorDesc = 'Method not supported';
            $strErrorHeader = 'HTTP/1.1 422 Unprocessable Entity';
        }
        // send output 
        if (!$strErrorDesc) {
            $this->sendOutput(
                $responseData,
                array(
                    'Access-Control-Allow-Origin: *',
                    'Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept',
                    'Content-Type: text/plain', 
                    'HTTP/1.1 200 OK')
            );
        } else {
            $this->sendOutput(json_encode(array('error' => $strErrorDesc)), 
                array('Content-Type: application/json', $strErrorHeader)
            );
        }
    }

    public function fetchAction()
    {
        $strErrorDesc = '';
        $requestMethod = $_SERVER["REQUEST_METHOD"];
        $arrQueryStringParams = $this->getQueryStringParams();
        if (strtoupper($requestMethod) == 'GET') {
            try {
                $sampleModel = new SampleModel();
                $since = date('Y-m-d H:i', strtotime('-1 hour'));
                $until = date('Y-m-d H:i');
                $format = "text";
                if (isset($arrQueryStringParams['since']) && $arrQueryStringParams['since']) {
                    $since = $arrQueryStringParams['since'];
                }
                if (isset($arrQueryStringParams['until']) && $arrQueryStringParams['until']) {
                    $until = $arrQueryStringParams['until'];
                }
                error_log("since " . $since . " until " . $until);
                $response = $sampleModel->get($since, $until);
                $responseData = "timestamp,CO2_1,CO2_2,CO2_3,CO2_4,CO2_5,CO2_6,O2_1,O2_2,O2_3,O2_4,O2_5,O2_6,\n";
                $responseData .= implode("\n", $response);
                // $responseData = json_encode($response);
            } catch (Error $e) {
                $strErrorDesc = $e->getMessage().'Something went wrong! Please contact support.';
                $strErrorHeader = 'HTTP/1.1 500 Internal Server Error';
            }
        } else {
            $strErrorDesc = 'Method not supported';
            $strErrorHeader = 'HTTP/1.1 422 Unprocessable Entity';
        }
        // send output 
        if (!$strErrorDesc) {
            if ($format == "file") {
                $this->sendOutput(
                    $responseData,
                    array(
                        'Content-Description: File Transfer',
                        'Access-Control-Allow-Origin: *',
                        'Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept',
                            // 'Content-Type: application/octet-stream',
                        "Content-Disposition: attachment; filename=\"sample-" . $since . "-to-" . $until . ".csv\"",
                        'Content-Type: text/plain',
                        'HTTP/1.1 200 OK')
                );    
            } else {
                $this->sendOutput(
                    $responseData,
                    array(
                        'Access-Control-Allow-Origin: *',
                        'Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept',
                        'Content-Type: text/plain',
                        'HTTP/1.1 200 OK')
                    );
            }
        } else {
            $this->sendOutput(json_encode(array('error' => $strErrorDesc)), 
                array('Content-Type: application/json', $strErrorHeader)
            );
        }
    }

    public function writeAction()
    {
        $strErrorDesc = '';
        $requestMethod = $_SERVER["REQUEST_METHOD"];
        $arrQueryStringParams = $this->getQueryStringParams();
        if (strtoupper($requestMethod) == 'GET') {
            try {
                $sampleModel = new SampleModel();
                if (!isset($arrQueryStringParams['data']) || !isset($arrQueryStringParams['data'])) {
                    $strErrorDesc = 'Data parameter not found';
                    $strErrorHeader = 'HTTP/1.1 400 Bad Request';
                } else {
                    $data = $arrQueryStringParams['data'];
                    error_log($data);
                    $response = $sampleModel->set($data);
                    $responseData = json_encode($response);;
                }
            } catch (Error $e) {
                $strErrorDesc = $e->getMessage().'Something went wrong! Please contact support.';
                $strErrorHeader = 'HTTP/1.1 500 Internal Server Error';
            }
        } else {
            $strErrorDesc = 'Method not supported';
            $strErrorHeader = 'HTTP/1.1 422 Unprocessable Entity';
        }
        // send output 
        if (!$strErrorDesc) {
            $this->sendOutput(
                $responseData,
                array('Content-Type: application/json', 'HTTP/1.1 200 OK')
            );
        } else {
            $this->sendOutput(json_encode(array('error' => $strErrorDesc)), 
                array('Content-Type: application/json', $strErrorHeader)
            );
        }
    }
}