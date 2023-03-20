<?php
require __DIR__ . "/inc/bootstrap.php";
$uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
$uri = explode( '/', $uri );
if ((isset($uri[1]) && $uri[1] != 'sample') || isset($uri[3])) {
    require PROJECT_ROOT_PATH . "/controller/api/sample-controller.php";
    $objFeedController = new SampleController();
    $strMethodName = $uri[3] . 'Action';
    $objFeedController->{$strMethodName}();
    return;
}

header("HTTP/1.1 404 Not Found");
echo("/sample/list");
echo("/sample/set");
?>
